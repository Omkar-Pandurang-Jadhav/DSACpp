/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell 
one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
*/


/*
====================================================================
INTUITION
====================================================================

In this problem, after selling a stock, we cannot buy on the very next
day because of the one-day cooldown. Instead of introducing a separate
cooldown state, we directly encode this restriction into the recursion.

Let

f(ind, buy)

represent the maximum profit that can be earned starting from day
'ind', where 'buy' indicates whether we are allowed to buy a stock.

If buy = 1, we currently do not own any stock. We have two choices.
Either buy today's stock, giving a profit of
-prices[ind] + f(ind+1,0), or skip today's stock and move to the next
day, giving f(ind+1,1). We take the maximum of these two choices.

If buy = 0, we already own a stock. Again, we have two choices.
Either sell today's stock, giving a profit of
prices[ind] + f(ind+2,1), or continue holding the stock, giving
f(ind+1,0). Notice that after selling, we move directly to day
'ind+2' because day 'ind+1' is the mandatory cooldown day during which
buying is not allowed.

The recursion stops when the index becomes greater than or equal to
the number of days (ind >= n). At this point, no further transactions
are possible, so the maximum profit is 0.

Since the same states are visited multiple times, we store every
computed answer in a DP table where dp[ind][buy] represents the
maximum profit for that state. Before solving any state, we first
check whether its answer has already been computed. This removes all
overlapping subproblems while keeping the recurrence unchanged.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*2)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*2)

for DP table

+

O(N)

auxiliary recursion stack.
*/


class Solution {
public:
    int f(vector<int> &prices,int n,int ind,int buy,vector<vector<int>> &dp){
        if(ind>=n) return 0;
        int profit=INT_MIN;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=max(-prices[ind]+f(prices,n,ind+1,0,dp),f(prices,n,ind+1,1,dp));
        }
        else{
            profit=max(prices[ind]+f(prices,n,ind+2,1,dp),f(prices,n,ind+1,0,dp));
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,n,0,1,dp);
    }
};
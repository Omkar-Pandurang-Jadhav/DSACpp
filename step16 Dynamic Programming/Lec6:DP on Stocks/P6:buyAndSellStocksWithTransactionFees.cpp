/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee 
representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to 
pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/



/*
====================================================================
INTUITION
====================================================================

This problem is similar to the basic Buy and Sell Stock problem, with
one additional constraint: every time we sell a stock, we must pay a
transaction fee. Instead of changing the DP state, we simply subtract
the fee when performing the sell operation.

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
prices[ind] - fee + f(ind+1,1), or continue holding the stock, giving
f(ind+1,0). The transaction fee is deducted only when selling because
a transaction is considered complete only after the stock is sold.

The recursion stops when all days have been processed (ind == n). At
this point, no further transactions are possible, so the maximum
profit is 0.

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
    int f(vector<int> &prices,int n,int ind,int buy,int fee,vector<vector<int>> &dp){
        if(ind==n) return 0;
        int profit=INT_MIN;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=max(-prices[ind]+f(prices,n,ind+1,0,fee,dp),f(prices,n,ind+1,1,fee,dp));
        }
        else{
            profit=max(prices[ind]-fee+f(prices,n,ind+1,1,fee,dp),f(prices,n,ind+1,0,fee,dp));
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,n,0,1,fee,dp);
    }
};
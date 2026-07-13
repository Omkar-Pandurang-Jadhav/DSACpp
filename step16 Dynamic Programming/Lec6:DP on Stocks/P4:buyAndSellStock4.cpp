/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and 
sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and 
sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/



/*
====================================================================
INTUITION
====================================================================

This problem is a generalization of the previous stock problem. Instead
of allowing at most two transactions, we are allowed to complete at
most k transactions. A transaction is considered complete only when a
stock is sold. Therefore, we keep track of three pieces of information:
the current day, whether we are allowed to buy, and the number of
completed transactions.

Let

f(ind, buy, cnt)

represent the maximum profit that can be earned starting from day
'ind', where 'buy' indicates whether we are allowed to buy a stock,
and 'cnt' represents the number of completed transactions.

If buy = 1, we currently do not own any stock. We have two choices.
Either buy today's stock, giving a profit of
-prices[ind] + f(ind+1,0,cnt), or skip today's stock and move to the
next day, giving f(ind+1,1,cnt). Buying does not complete a
transaction, so 'cnt' remains unchanged.

If buy = 0, we already own a stock. Again, we have two choices.
Either sell today's stock, giving a profit of
prices[ind] + f(ind+1,1,cnt+1), or continue holding the stock and move
to the next day, giving f(ind+1,0,cnt). Selling completes one
transaction, so the transaction count is increased by one.

The recursion stops in two situations. If we have already completed
'k' transactions (cnt == k), no further transactions are allowed, so
the profit is 0. Similarly, if all days have been processed
(ind == n), no more profit can be earned, so we also return 0.

Since the same states are visited multiple times, we store every
computed answer in a 3D DP table where
dp[ind][buy][cnt] represents the maximum profit for that state. Before
solving any state, we first check whether its answer has already been
computed. This eliminates all overlapping subproblems while keeping
the recurrence unchanged.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*2*K)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*2*K)

for DP table

+

O(N)

auxiliary recursion stack.
*/


class Solution {
public:
    int f(vector<int> &prices,int n,int ind,int buy,int cnt,int k,vector<vector<vector<int>>> &dp){
        if(cnt==k) return 0;
        if(ind==n) return 0;
        int profit=INT_MIN;
        if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];
        if(buy){
            profit=max(-prices[ind]+f(prices,n,ind+1,0,cnt,k,dp),f(prices,n,ind+1,1,cnt,k,dp));
        }
        else {
            profit=max(prices[ind]+f(prices,n,ind+1,1,cnt+1,k,dp),f(prices,n,ind+1,0,cnt,k,dp));
        }
        return dp[ind][buy][cnt]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(prices,n,0,1,0,k,dp);
    }
};
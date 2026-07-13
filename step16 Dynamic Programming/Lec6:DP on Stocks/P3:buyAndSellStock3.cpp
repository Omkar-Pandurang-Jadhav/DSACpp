/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at
 the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*
====================================================================
INTUITION
====================================================================

This problem is an extension of the previous stock problem. The only
difference is that we are allowed to complete at most two
transactions. A transaction is considered complete only when we sell
a stock. Therefore, in addition to the day index and the buying
state, we also need to keep track of the number of completed
transactions.

Let

f(ind, buy, cnt)

represent the maximum profit that can be earned starting from day
'ind', where 'buy' indicates whether we are allowed to buy a stock,
and 'cnt' represents the number of completed transactions.

If buy = 1, we currently do not own any stock. We have two choices.
Either buy today's stock, giving a profit of
-prices[ind] + f(ind+1,0,cnt), or skip today's stock and move to the
next day, giving f(ind+1,1,cnt). Buying a stock does not complete a
transaction, so 'cnt' remains unchanged.

If buy = 0, we already own a stock. Again, we have two choices.
Either sell today's stock, giving a profit of
prices[ind] + f(ind+1,1,cnt+1), or continue holding the stock and move
to the next day, giving f(ind+1,0,cnt). Selling completes one
transaction, so the transaction count is increased by one.

The recursion stops in two situations. If two transactions have
already been completed (cnt == 2), no further transactions are
allowed, so the profit is 0. Similarly, if all days have been
processed (ind == n), no more profit can be earned, so we also return
0.

====================================================================
TIME COMPLEXITY
====================================================================

O(2^N)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N)

Auxiliary recursion stack.
*/
// Recursive 
class Solution {
public:
    int f(vector<int> &prices,int n,int ind,int buy,int cnt){
        if(cnt==2) return 0;
        if(ind==n) return 0;
        int profit=INT_MIN;
        
        if(buy){
            profit=max(-prices[ind]+f(prices,n,ind+1,0,cnt),f(prices,n,ind+1,1,cnt));
        }
        else {
            profit=max(prices[ind]+f(prices,n,ind+1,1,cnt+1),f(prices,n,ind+1,0,cnt));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cnt=0;
        return f(prices,n,0,1,cnt);
    }
};


// Memoization

/*
====================================================================
INTUITION
====================================================================

The recursive solution repeatedly computes the same state
(ind, buy, cnt), leading to many overlapping subproblems. To avoid
this, we store the answer of every computed state in a 3D DP table,
where dp[ind][buy][cnt] represents the maximum profit that can be
earned starting from day 'ind', with the current buying state 'buy'
and 'cnt' completed transactions.

Before solving any state, we first check whether its answer has
already been computed. If it has, we simply return the stored value
instead of solving the same subproblem again. Since the transaction
count also affects the future decisions, it must be included as part
of the DP state. Thus, every unique combination of (ind, buy, cnt) is
computed only once while the recurrence remains exactly the same as
the recursive solution.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*2*3)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*2*3)

for DP table

+

O(N)

auxiliary recursion stack.
*/


class Solution {
public:
    int f(vector<int> &prices,int n,int ind,int buy,int cnt,vector<vector<vector<int>>> &dp){
        if(cnt==2) return 0;
        if(ind==n) return 0;
        int profit=INT_MIN;
        if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];
        if(buy){
            profit=max(-prices[ind]+f(prices,n,ind+1,0,cnt,dp),f(prices,n,ind+1,1,cnt,dp));
        }
        else {
            profit=max(prices[ind]+f(prices,n,ind+1,1,cnt+1,dp),f(prices,n,ind+1,0,cnt,dp));
        }
        return dp[ind][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cnt=0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,n,0,1,cnt,dp);
    }
};



// Tabulation

/*
====================================================================
INTUITION
====================================================================

The memoized solution can be converted into an iterative bottom-up DP.
Let dp[ind][buy][cnt] represent the maximum profit that can be earned
starting from day 'ind', where 'buy' indicates whether we are allowed
to buy a stock and 'cnt' represents the number of completed
transactions. Since every state depends only on the next day, we fill
the DP table from the last day towards the first day.

There are two base cases. First, after the last day (ind == n), no
more transactions are possible, so the profit is 0 regardless of the
buy state or transaction count. Second, if two transactions have
already been completed (cnt == 2), we are not allowed to perform any
more transactions, so the profit is again 0 for every day and buying
state.

For every day, if buy = 1, we have two choices. Either buy the stock
today, giving a profit of -prices[ind] + dp[ind+1][0][cnt], or skip
today and move to the next day, giving dp[ind+1][1][cnt]. We take the
maximum of these two values.

If buy = 0, we already own a stock. We can either sell it today,
giving a profit of prices[ind] + dp[ind+1][1][cnt+1], which completes
one transaction, or continue holding the stock, giving
dp[ind+1][0][cnt]. Again, we take the maximum of these two choices.

The final answer is stored in dp[0][1][0], which represents the
maximum profit starting from the first day, initially allowed to buy,
with zero completed transactions.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*2*3)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*2*3)
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cnt=0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                dp[n][i][j]=0;

            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=1;j++){
                dp[i][j][2]=0;
            }
        }

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=0;cnt<=1;cnt++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[ind]+dp[ind+1][0][cnt],dp[ind+1][1][cnt]);
                    }
                    else {
                        profit=max(prices[ind]+dp[ind+1][1][cnt+1],dp[ind+1][0][cnt]);
                    }
                    dp[ind][buy][cnt]=profit;
                }
            }
        }
        return dp[0][1][0];
    }
};



// Space Optimization 2 arrays
/*
====================================================================
INTUITION
====================================================================

Observe that in the tabulation solution, every state
dp[ind][buy][cnt] depends only on the states of the next day,
dp[ind+1][...][...]. Therefore, instead of storing the entire 3D DP
table, we only need to store the answers for the next day. We use the
array 'prev' to represent dp[ind+1] and the array 'cur' to represent
dp[ind].

The base cases remain the same. After the last day, the profit is 0
for every buying state and transaction count. Similarly, if two
transactions have already been completed, no further transactions are
allowed, so the profit is 0.

For every day, if buy = 1, we either buy today's stock or skip it.
Buying gives a profit of -prices[ind] + prev[0][cnt], while skipping
gives prev[1][cnt]. We take the maximum of these two choices.

If buy = 0, we either sell today's stock or continue holding it.
Selling gives a profit of prices[ind] + prev[1][cnt+1], which
completes one transaction, while holding gives prev[0][cnt]. Again,
we take the maximum of these two values.

Once all buying states and transaction counts for the current day have
been computed, 'cur' is copied into 'prev', and the process continues
for the previous day. This reduces the space complexity from
O(N*2*3) to O(2*3), while preserving the same recurrence.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*2*3)

====================================================================
SPACE COMPLEXITY
====================================================================

O(2*3)

Two arrays of size 2 × 3 are stored.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cnt=0;
        vector<vector<int>> prev(2,vector<int>(3,-1));
        vector<vector<int>> cur(2,vector<int>(3,-1));
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                prev[i][j]=0;

            }
        }
        for(int j=0;j<=1;j++){
            cur[j][2]=0;
        }
        

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=0;cnt<=1;cnt++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[ind]+prev[0][cnt],prev[1][cnt]);
                    }
                    else {
                        profit=max(prices[ind]+prev[1][cnt+1],prev[0][cnt]);
                    }
                    cur[buy][cnt]=profit;
                }
            }
            prev=cur;
        }
        return prev[1][0];
    }
};


/*
====================================================================
INTUITION
====================================================================

Instead of storing DP states for every day, observe that there are
only four meaningful states throughout the entire process.

hold1

Maximum profit after buying the first stock.

release1

Maximum profit after selling the first stock.

hold2

Maximum profit after buying the second stock.

release2

Maximum profit after selling the second stock.

Initially, no stock has been bought, so both buying states are
initialized to negative infinity, while both selling states are
initialized to 0 because no profit has been earned yet.

For every price, we update these four states in order.

First, update hold1 by deciding whether to keep the previous first
buy or buy today's stock.

Next, update release1 by deciding whether to keep the previous first
sell or sell the first stock today.

Then, update hold2 by deciding whether to keep the previous second
buy or buy the second stock today using the profit earned from the
first completed transaction.

Finally, update release2 by deciding whether to keep the previous
second sell or sell the second stock today.

At the end of the traversal, release2 stores the maximum profit after
completing at most two transactions.

====================================================================
TIME COMPLEXITY
====================================================================

O(N)

====================================================================
SPACE COMPLEXITY
====================================================================

O(1)

Only four variables are used.
*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1,hold2,release1,release2;
        hold1=hold2=INT_MIN;
        release1=release2=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            hold1=max(hold1,-prices[i]);
            release1=max(release1,hold1+prices[i]);
            hold2=max(hold2,-prices[i]+release1);
            release2=max(release2,hold2+prices[i]);
        }

        return release2;
    }
};
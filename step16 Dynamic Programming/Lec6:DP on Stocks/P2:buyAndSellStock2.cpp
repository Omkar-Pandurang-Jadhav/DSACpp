/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

/*
====================================================================
INTUITION
====================================================================

At every day, we have only two possible states. Either we are allowed
to buy a stock (buy = 1), which means we currently do not own any
stock, or we already own a stock (buy = 0), which means our next
decision is whether to sell it or continue holding it.

Let f(ind, buy) represent the maximum profit that can be earned
starting from day 'ind' when the current state is 'buy'. If buy = 1,
we have two choices. We can buy the stock today, which gives a profit
of -prices[ind] + f(ind+1,0), or we can skip today's stock and move to
the next day, giving f(ind+1,1). Since our objective is to maximize
the profit, we take the maximum of these two choices.

If buy = 0, it means we already own a stock. Again, we have two
choices. We can sell the stock today, which gives a profit of
prices[ind] + f(ind+1,1), or we can continue holding the stock and
move to the next day, giving f(ind+1,0). We again take the maximum of
these two choices.

The base case occurs when we reach beyond the last day (ind == n). At
this point, no further transactions can be performed, so the maximum
profit that can be earned is 0.

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

class Solution {
public:
    int f(vector<int> &prices,int n,int ind,int buy){
        if(ind==n) return 0;
        int profit=INT_MIN;
        if(buy){
            profit=max(-prices[ind]+f(prices,n,ind+1,0),f(prices,n,ind+1,1));
        }
        else {
            profit=max(prices[ind]+f(prices,n,ind+1,1),f(prices,n,ind+1,0));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        return f(prices,n,0,1);
    }
};


/*
====================================================================
INTUITION
====================================================================

The recursive solution computes the same state (ind, buy) multiple
times, leading to a large amount of repeated work. To avoid this, we
store the answer of every computed state in a DP table, where
dp[ind][buy] represents the maximum profit that can be earned
starting from day 'ind' with the current buying state 'buy'. Before
solving any state, we first check whether its answer has already been
computed. If it has, we simply return the stored value instead of
recomputing it. This eliminates all overlapping subproblems while
keeping the same recurrence as the recursive solution.

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
        if(ind==n) return 0;
        int profit=INT_MIN;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=max(-prices[ind]+f(prices,n,ind+1,0,dp),f(prices,n,ind+1,1,dp));
        }
        else {
            profit=max(prices[ind]+f(prices,n,ind+1,1,dp),f(prices,n,ind+1,0,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,n,0,1,dp);
    }
};




/*
====================================================================
INTUITION
====================================================================

The memoized solution can be converted into an iterative bottom-up DP.
Let dp[ind][buy] represent the maximum profit that can be earned
starting from day 'ind' when the current state is 'buy'. Since every
state depends only on the next day, we fill the DP table from the last
day towards the first day.

The base case corresponds to the situation after the last day
(ind == n). At this point, no further transactions are possible,
regardless of whether we are allowed to buy or currently own a stock.
Therefore, dp[n][0] = 0 and dp[n][1] = 0.

For every day, if buy = 1, we have two choices. Either buy the stock
today, giving a profit of -prices[ind] + dp[ind+1][0], or skip today's
stock and keep the buying option available, giving dp[ind+1][1]. We
take the maximum of these two values.

If buy = 0, we already own a stock. We can either sell it today,
giving a profit of prices[ind] + dp[ind+1][1], or continue holding the
stock, giving dp[ind+1][0]. Again, we take the maximum of these two
choices.

The final answer is stored in dp[0][1], which represents the maximum
profit starting from the first day when we are initially allowed to
buy.

====================================================================
TIME COMPLEXITY
====================================================================

O(N)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        for(int i=0;i<2;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;
                if(j){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else {
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
};



/*
====================================================================
INTUITION
====================================================================

From the tabulation solution, observe that every state dp[ind][buy]
depends only on the values of the next day, namely dp[ind+1][0] and
dp[ind+1][1]. None of the earlier rows are required once the current
row has been computed. Therefore, instead of storing the entire DP
table, we only keep two arrays of size 2. The array 'prev' stores the
answers for the next day (dp[ind+1]), while the array 'cur' stores the
answers for the current day (dp[ind]). For each day, we compute both
buy states using the values stored in 'prev'. Once the current day's
answers have been calculated, we simply copy 'cur' into 'prev' and
continue processing the previous day. This reduces the space
complexity from O(N*2) to O(1) while preserving the same DP
transition.

====================================================================
TIME COMPLEXITY
====================================================================

O(N)

====================================================================
SPACE COMPLEXITY
====================================================================

O(1)

Only two arrays of size 2 are stored.
*/


class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(2,-1);
        vector<int> cur(2,-1);
        prev[0]=0;
        prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;
                if(j){
                    profit=max(-prices[i]+prev[0],prev[1]);
                }
                else {
                    profit=max(prices[i]+prev[1],prev[0]);
                }
                cur[j]=profit;
            }
            prev=cur;
        }
        return prev[1];
    }
};



/*
====================================================================
INTUITION
====================================================================

Normally, we compute the current day's answers in a separate array
'cur' using the values stored in the next day's array 'prev'. At first
glance, using only one array seems impossible because updating
prev[0] would overwrite its old value before prev[1] is computed.
However, this stock DP has a special property that makes the
optimization valid.

First, we update prev[0], which represents the current day's "not
buy" state.

prev[0] = max(prices[i] + prev[1], prev[0])

After this update, prev[0] no longer stores the next day's answer. It
now stores cur[0]. Next, we compute prev[1] using this updated value.

prev[1] = max(-prices[i] + prev[0], prev[1])

Although it appears that we are using the wrong value, the result
remains correct because the updated prev[0] can only be one of two
values. Either it remains equal to the old prev[0], in which case the
transition is exactly the same as the original DP, or it becomes
prices[i] + old prev[1]. In the second case,

-price[i] + prev[0]

becomes

-price[i] + prices[i] + old prev[1]

which simplifies to

old prev[1].

Therefore, the transition reduces to

max(old prev[1], old prev[1]),

which is exactly the same result as the original recurrence.
Hence, overwriting prev[0] before computing prev[1] never changes the
final answer.

This optimization is a special property of this stock DP recurrence
and should not be generalized to other DP problems such as LCS,
Edit Distance or Wildcard Matching, where overwriting states before
they are used would produce incorrect results.

====================================================================
TIME COMPLEXITY
====================================================================

O(N)

====================================================================
SPACE COMPLEXITY
====================================================================

O(1)

Only one array of size 2 is used.
*/


class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(2,-1);
       // vector<int> cur(2,-1);
        prev[0]=0;
        prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=0;
                if(j){
                    profit=max(-prices[i]+prev[0],prev[1]);
                }
                else {
                    profit=max(prices[i]+prev[1],prev[0]);
                }
                prev[j]=profit;
            }
           // prev=cur;
        }
        return prev[1];
    }
};
/*
====================================================================
INTUITION
====================================================================

This problem is an extension of the

        0/1 Knapsack

The only difference is

0/1 Knapsack

        -> Every item can be taken only once.

Unbounded Knapsack

        -> Every item can be taken unlimited times.

------------------------------------------------------------

For every item, we again have two choices.

1. Do not take the current item.
2. Take the current item.

------------------------------------------------------------

Not Take

If we decide not to take the current item,

we move to the previous item.

Hence,

        f(ind-1,target)

------------------------------------------------------------

Take

Since the current item can be taken again,

after taking it,

we remain at the same index.

Only the remaining capacity decreases.

Therefore,

        f(ind,target-weight[ind])

instead of

        f(ind-1,target-weight[ind])

Profit of the current item is also added.

Hence,

        f(ind,target-weight[ind]) + profit[ind]

------------------------------------------------------------

Base Case

When only one item remains,

we can fill the remaining capacity using only that item.

Suppose

weight = 2

profit = 5

capacity = 10

Then,

maximum copies that can be taken

        = 10 / 2 = 5

Total profit

        = 5 × 5 = 25

Therefore,

        (target / weight[0]) * profit[0]

If the remaining capacity is smaller than its weight,

the answer automatically becomes

0

because

        target / weight[0]

becomes

0.

------------------------------------------------------------

Recursive Relation

Maximum Profit

=

max(

Not Take,

Take

)

====================================================================
TIME COMPLEXITY
====================================================================

Recursion

Exponential

Memoization

O(N × W)

====================================================================
SPACE COMPLEXITY
====================================================================

Recursion

O(N)

Memoization

O(N × W)

+

O(N)

auxiliary recursion stack.

====================================================================
WHY DOES THE TAKE CASE NOT MOVE TO ind-1?

Because every item can be chosen multiple times.

After taking the current item,

it is still available.

Therefore,

Take

=

f(ind,target-weight[ind])

This is the defining property of

        Unbounded Knapsack.
*/


// Recursion

int f(int ind,int target,vector<int> &profit,vector<int> &weight){

    // Base Case
    if(ind==0){
        if(target>=weight[ind])
            return (target/weight[ind])*profit[ind];

        return 0;
    }

    // Knapsack completely filled
    if(target==0)
        return 0;

    // Do not take current item
    int notTake=f(ind-1,target,profit,weight);

    // Take current item
    int Take=0;
    if(target>=weight[ind])
        Take=f(ind,target-weight[ind],profit,weight)+profit[ind];

    // Return maximum profit
    return max(notTake,Take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    return f(n-1,w,profit,weight);
}



// Memoization

/*
====================================================================
INTUITION
====================================================================

This is the memoized version of Unbounded Knapsack.

The recursive state is

        dp[ind][target]

which represents

Maximum profit obtainable using items

0...ind

with remaining capacity

target.

If a state has already been computed,

reuse it instead of solving it again.

Everything else remains identical to recursion.

====================================================================
TIME COMPLEXITY
====================================================================

O(N × W)

Each state is computed only once.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N × W)

for DP table

+

O(N)

auxiliary recursion stack.
*/

#include<bits/stdc++.h>

int f(int ind,int target,vector<int> &profit,vector<int> &weight,vector<vector<int>> &dp){

    // Base Case
    if(ind==0){
        return (target/weight[ind])*profit[ind];
    }

    // Knapsack completely filled
    if(target==0)
        return 0;

    // Already computed
    if(dp[ind][target]!=-1)
        return dp[ind][target];

    // Do not take current item
    int notTake=f(ind-1,target,profit,weight,dp);

    // Take current item
    int Take=0;
    if(target>=weight[ind])
        Take=f(ind,target-weight[ind],profit,weight,dp)+profit[ind];

    // Store and return answer
    return dp[ind][target]=max(notTake,Take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));

    return f(n-1,w,profit,weight,dp);
}


// Tabulation

/*
====================================================================
INTUITION
====================================================================

This is the Tabulation approach for Unbounded Knapsack.

The recursive state

        dp[ind][target]

represents

Maximum profit that can be obtained using items

0...ind

with remaining capacity

target.

------------------------------------------------------------

Base Case

When only the first item is available,

we can fill the knapsack using only that item.

Maximum copies possible

        = target / weight[0]

Therefore,

        dp[0][target]

=

(target / weight[0]) × profit[0]

------------------------------------------------------------

Transition

For every item,

we have two choices.

1. Do not take the current item.

        dp[ind-1][target]

2. Take the current item.

Since the item can be taken unlimited times,

the index does not change.

Remaining capacity becomes

        target - weight[ind]

Therefore,

Take

=

dp[ind][target-weight[ind]] + profit[ind]

Finally,

Maximum Profit

=

max(

Not Take,

Take

)

====================================================================
TIME COMPLEXITY
====================================================================

O(N × W)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N × W)
*/

#include<bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));

    // Base Case
    for(int i=0;i<=w;i++){
        dp[0][i]=(i/weight[0])*profit[0];
    }

    // Fill DP Table
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=w;target++){

            // Do not take current item
            int notTake=dp[ind-1][target];

            // Take current item
            int Take=0;
            if(target>=weight[ind])
                Take=dp[ind][target-weight[ind]]+profit[ind];

            // Store maximum profit
            dp[ind][target]=max(notTake,Take);
        }
    }

    return dp[n-1][w];
}



// Space Optimization

/*
====================================================================
INTUITION
====================================================================

This is the Space Optimized version of Unbounded Knapsack.

From the tabulation solution,

we observe that

dp[ind]

depends only on

1. dp[ind-1]

2. dp[ind]

Therefore,

instead of storing the entire DP table,

we only store

prev

which represents

        dp[ind-1]

and

cur

which represents

        dp[ind]

------------------------------------------------------------

Why do we use

        cur[target-weight[ind]]

instead of

        prev[target-weight[ind]]?

Because in the Take case,

the recurrence is

        dp[ind][target-weight[ind]]

Notice that

the index

does not change.

Therefore,

during space optimization,

dp[ind]

is represented by

        cur

This is the defining property of

        Unbounded Knapsack.

------------------------------------------------------------

Transition

Not Take

=

prev[target]

Take

=

cur[target-weight[ind]] + profit[ind]

Maximum Profit

=

max(

Not Take,

Take

)

====================================================================
TIME COMPLEXITY
====================================================================

O(N × W)

====================================================================
SPACE COMPLEXITY
====================================================================

O(W)
*/

#include<bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> prev(w+1,-1);
    vector<int> cur(w+1,-1);

    // Base Case
    for(int i=0;i<=w;i++){
        prev[i]=(i/weight[0])*profit[0];
    }

    // Fill DP Arrays
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=w;target++){

            // Do not take current item
            int notTake=prev[target];

            // Take current item
            int Take=0;
            if(target>=weight[ind])
                Take=cur[target-weight[ind]]+profit[ind];

            // Store maximum profit
            cur[target]=max(notTake,Take);
        }

        prev=cur;
    }

    return prev[w];
}
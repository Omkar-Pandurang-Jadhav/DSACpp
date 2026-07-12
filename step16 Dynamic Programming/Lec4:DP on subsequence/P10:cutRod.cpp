/*
====================================================================
INTUITION
====================================================================

This problem is very similar to

        Unbounded Knapsack.

Think of every possible rod length as an item.

Length

1 2 3 4 ... N

Price

p1 p2 p3 p4 ... pN

Our goal is to obtain the maximum selling price by cutting the rod.

------------------------------------------------------------

For every possible first cut,

we have one choice.

Suppose the current rod length is

        n

We can cut

Length 1

Remaining rod

        n-1

Profit

        price[0]

------------------------------------------------------------

We can cut

Length 2

Remaining rod

        n-2

Profit

        price[1]

------------------------------------------------------------

Similarly,

Length 3

Remaining rod

        n-3

Profit

        price[2]

and so on.

------------------------------------------------------------

For every possible first cut,

Profit

=

Price of current piece

+

Maximum profit obtainable from the remaining rod.

Therefore,

we recursively solve the remaining rod.

------------------------------------------------------------

Base Case

When

        n == 0

the rod has no remaining length.

Hence,

Maximum profit

=

0

------------------------------------------------------------

Recursive Relation

Maximum Profit

=

Maximum of

{

price[0] + f(n-1),

price[1] + f(n-2),

...

price[n-1] + f(0)

}

Since we try every possible first cut,

the maximum among all choices is the answer.

====================================================================
TIME COMPLEXITY
====================================================================

Recursion

Exponential

====================================================================
SPACE COMPLEXITY
====================================================================

O(N)

Auxiliary recursion stack.
*/

#include<bits/stdc++.h>

int cutRod(vector<int> &price, int n){

    // Rod completely cut
    if(n==0)
        return 0;

    int max_price=INT_MIN;

    // Try every possible first cut
    for(int i=0;i<n;i++){

        int p=0;

        if(n-i-1>=0)
            p=cutRod(price,n-i-1)+price[i];

        // Keep maximum profit
        max_price=max(max_price,p);
    }

    return max_price;
}


/*
====================================================================
INTUITION
====================================================================

This is the Memoization version of Rod Cutting.

The recursive state

        dp[n]

represents

Maximum profit obtainable from a rod of length

        n.

If the answer for a rod length has already been computed,

reuse it instead of solving it again.

Everything else remains identical to recursion.

====================================================================
TIME COMPLEXITY
====================================================================

O(N²)

There are

N

states.

For every state,

we try every possible first cut.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N)

for DP array

+

O(N)

auxiliary recursion stack.
*/

#include<bits/stdc++.h>

int f(vector<int> &price,int n,vector<int> &dp){

    // Rod completely cut
    if(n==0)
        return 0;

    // Already computed
    if(dp[n]!=-1)
        return dp[n];

    int max_price=INT_MIN;

    // Try every possible first cut
    for(int i=0;i<n;i++){

        int p=0;

        if(n-i-1>=0)
            p=f(price,n-i-1,dp)+price[i];

        // Keep maximum profit
        max_price=max(max_price,p);
    }

    // Store and return answer
    return dp[n]=max_price;
}

int cutRod(vector<int> &price, int n){

    vector<int> dp(n+1,-1);

    int ans=f(price,n,dp);

    return ans;
}




/*
====================================================================
INTUITION
====================================================================

This is the Tabulation (Bottom-Up DP) version of Rod Cutting.

The DP state is

        dp[i]

which represents

Maximum profit obtainable from a rod of length

        i.

------------------------------------------------------------

Instead of solving recursively,

we build the answer from smaller rod lengths to larger rod lengths.

Base Case

dp[0] = 0

because a rod of length 0 has no value.

------------------------------------------------------------

For every rod length

        i

we try every possible first cut.

Suppose

        i = 5

Possible first cuts are

Length 1

Profit = price[0] + dp[4]

Length 2

Profit = price[1] + dp[3]

Length 3

Profit = price[2] + dp[2]

Length 4

Profit = price[3] + dp[1]

Length 5

Profit = price[4] + dp[0]

------------------------------------------------------------

For every possible first cut,

Current Profit

=

Price of current piece

+

Maximum profit obtainable from the remaining rod.

We take the maximum among all possible first cuts.

====================================================================
TIME COMPLEXITY
====================================================================

O(N²)

Outer loop -> N

Inner loop -> N

====================================================================
SPACE COMPLEXITY
====================================================================

O(N)

One DP array is used.
*/

#include<bits/stdc++.h>

int cutRod(vector<int> &price, int n){

    vector<int> dp(n+1,-1);

    // Base Case
    dp[0]=0;

    // Build answers from smaller rod lengths to larger rod lengths
    for(int i=1;i<=n;i++){

        int max_price=INT_MIN;

        // Try every possible first cut
        for(int j=0;j<i;j++){

            int p=0;

            if(i-j-1>=0)
                p=price[j]+dp[i-j-1];

            // Keep maximum profit
            max_price=max(max_price,p);
        }

        dp[i]=max_price;
    }

    return dp[n];
}
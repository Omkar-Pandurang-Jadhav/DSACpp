/*
====================================================================
INTUITION
====================================================================

This problem is very similar to

        Coin Change I (Minimum Coins)

The only difference is

Coin Change I

        -> Find the minimum number of coins.

Coin Change II

        -> Count the total number of combinations.

------------------------------------------------------------

For every coin, we have two choices.

1. Do not take the current coin.
2. Take the current coin.

----------------------------------------------------------------

Not Take

Move to the previous coin.

        ind - 1

because we have decided not to use the current coin.

----------------------------------------------------------------

Take

Since we have an infinite supply of every coin,

after taking the current coin,

we can still use the same coin again.

Therefore,

the index remains the same.

Remaining target becomes

        target - coins[ind]

Hence,

Take

=

f(ind, target - coins[ind])

instead of

        f(ind - 1, ...)

This is exactly why this problem belongs to

        Unbounded Knapsack.

----------------------------------------------------------------

Base Case

When only one coin remains,

it can form the target only if

        target

is exactly divisible by

        coins[0]

For example,

coin = 2

target = 8

Possible

2 + 2 + 2 + 2

Return

1

Otherwise,

return

0

----------------------------------------------------------------

Recursive Relation

Total Ways

=

Not Take

+

Take

because we need to count every possible combination.

====================================================================
TIME COMPLEXITY
====================================================================

Recursion

O(2^N)

Memoization

O(N × Amount)

Tabulation

O(N × Amount)

Space Optimization

O(Amount)

====================================================================
SPACE COMPLEXITY
====================================================================

Recursion

O(N)

Memoization

O(N × Amount)

+

O(N)

auxiliary recursion stack.

Tabulation

O(N × Amount)

Space Optimization

O(Amount)

====================================================================
WHY DO WE USE

        cur[target - coins[ind]]

IN SPACE OPTIMIZATION?

In the Take case,

the recurrence is

        dp[ind][target - coins[ind]]

Notice that

the index

        ind

does not change.

Therefore,

during space optimization,

dp[ind]

is represented by

        cur

Hence,

Take

=

cur[target - coins[ind]]

If we had written

        prev[target - coins[ind]]

it would incorrectly represent

        dp[ind-1][...]

which changes the recurrence completely.

This is the characteristic property of

        Unbounded Knapsack.
*/


// Recursion 

class Solution {
public:
    int f(int ind,int target,vector<int> &coins){
        if(ind==0){
            return target%coins[ind]==0;
        }

        int notTake=f(ind-1,target,coins);

        int Take=0;
        if(target>=coins[ind])
            Take=f(ind,target-coins[ind],coins);

        return notTake+Take;
    }

    int change(int amount, vector<int>& coins) {
        return f(coins.size()-1,amount,coins);
    }
};


// Memoization

class Solution {
public:
    int f(int ind,int target,vector<int> &coins,vector<vector<int>> &dp){
        if(ind==0){
            return target%coins[ind]==0;
        }

        if(dp[ind][target]!=-1)
            return dp[ind][target];

        int notTake=f(ind-1,target,coins,dp);

        int Take=0;
        if(target>=coins[ind])
            Take=f(ind,target-coins[ind],coins,dp);

        return dp[ind][target]=notTake+Take;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));

        return f(coins.size()-1,amount,coins,dp);
    }
};


// Tabulation

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<vector<long long>> dp(coins.size()+1,vector<long long>(amount+1,-1));

        for(int T=0;T<=amount;T++){
            dp[0][T]=T%coins[0]==0;
        }

        for(int ind=1;ind<coins.size();ind++){
            for(int target=0;target<=amount;target++){

                int notTake=dp[ind-1][target];

                int Take=0;
                if(target>=coins[ind])
                    Take=dp[ind][target-coins[ind]];

                dp[ind][target]=(long long)((long long)notTake+(long long)Take);
            }
        }

        return dp[coins.size()-1][amount];
    }
};


// Space Optimization

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<long long> prev(amount+1,-1);
        vector<long long> cur(amount+1,-1);

        for(int T=0;T<=amount;T++){
            prev[T]=T%coins[0]==0;
        }

        for(int ind=1;ind<coins.size();ind++){

            for(int target=0;target<=amount;target++){

                int notTake=prev[target];

                int Take=0;
                if(target>=coins[ind])
                    Take=cur[target-coins[ind]];

                cur[target]=(long long)((long long)notTake+(long long)Take);
            }

            prev=cur;
        }

        return prev[amount];
    }
};
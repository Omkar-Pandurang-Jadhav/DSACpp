/*
====================================================================
QUESTION
====================================================================

You are given an integer array 'coins' representing different coin
denominations and an integer 'amount'.

You have an infinite supply of every coin.

Return the minimum number of coins required to make the given amount.

If it is impossible to make the amount, return -1.

--------------------------------------------------------------------

Example:

coins = [1,2,5]

amount = 11

Output:

3

Explanation:

11 = 5 + 5 + 1

Hence, minimum coins = 3.

====================================================================
INTUITION
====================================================================

Yes!

This problem is very similar to

        Frog Jump with K Distance.

------------------------------------------------------------

Frog Jump

From stair 'i',

the frog can jump

1 step

2 steps

...

K steps

and we choose the jump having the minimum cost.

Recurrence

        dp[i]

=

minimum of

dp[i-1]

dp[i-2]

...

dp[i-k]

------------------------------------------------------------

Coin Change

Here,

our current state is the remaining amount.

Suppose,

current amount = X

From amount X,

we can reduce it by choosing

coin1

coin2

coin3

...

Every coin acts like one possible jump.

For every coin,

we move to

        X - coin

and add

1

because we have used one coin.

Among all possible choices,

we select the minimum.

Hence,

this problem is exactly

"Frog Jump with variable jump sizes"

where

Jump Size

=

Coin Value

and

Jump Cost

=

1 coin.

------------------------------------------------------------

Recursive State

f(amount)

=

Minimum coins required to form the given amount.

------------------------------------------------------------

Base Case

If

amount == 0

No more coins are required.

Return

0

------------------------------------------------------------

Recursive Relation

For every coin,

Try using it.

Remaining amount becomes

        amount - coin

The answer becomes

        1 + f(amount - coin)

Take the minimum over all possible coins.

------------------------------------------------------------

Memoization

Many amounts are computed repeatedly.

For example,

f(7)

may be reached from

f(8)

f(9)

f(12)

Instead of solving it multiple times,

store the answer in

dp[amount].

====================================================================
Time Complexity
====================================================================

O(Amount × Number of Coins)

Each amount is computed only once.

====================================================================
Space Complexity
====================================================================

O(Amount)

for DP array

+

O(Amount)

auxiliary recursion stack in the worst case.
*/

class Solution {
public:

    const int mod = 1e9 + 7;

    int f(int ind, vector<int> &coins, vector<int> &dp){

        if(ind == 0)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int mini = INT_MAX;

        for(int i = 0; i < coins.size(); i++){

            if(ind - coins[i] >= 0){

                int coinsSelected = (f(ind - coins[i], coins, dp) % mod + 1) % mod;

                mini = min(mini, coinsSelected);
            }
        }

        return dp[ind] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {


        vector<int> dp(amount + 1, -1);

        int a = f(amount, coins, dp);

        if(a > 10000)
            return -1;

        return a;
    }
};
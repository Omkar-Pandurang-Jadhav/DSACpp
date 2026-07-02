/*
====================================================================
QUESTION
====================================================================

You are given an array 'arr' of size 'n' containing positive integers
and an integer 'k'.

Find the number of subsets whose sum is exactly equal to 'k'.

Since the answer can be very large, return it modulo

                10^9 + 7

--------------------------------------------------------------------

Example:

Input:

arr = [1,1,4,5]
k = 5

Output:

3

Explanation:

Possible subsets are

[1,4]
[1,4]
[5]

The two 1's are considered different elements because they
belong to different indices.

====================================================================
INTUITION
====================================================================

This problem is almost identical to the Subset Sum problem.

The only difference is that instead of asking

"Does a subset exist?"

we are asked

"How many subsets exist?"

For every element, we again have only two choices.

1. Pick the current element.
2. Do not pick the current element.

If we pick the current element,

the remaining target becomes

        target - arr[ind]

If we do not pick it,

the target remains unchanged.

Unlike the Subset Sum problem where the answer was

        Pick OR Not Pick

here we need the total number of valid subsets.

Therefore, the recurrence becomes

        Pick + Not Pick

Since the same states are solved repeatedly,
we store the answer using Dynamic Programming.

--------------------------------------------------------------------
DP State
--------------------------------------------------------------------

dp[ind][target]

represents

"The number of subsets that can be formed using
elements from index 0 to ind whose sum is target."

--------------------------------------------------------------------
Base Case
--------------------------------------------------------------------

When only one element remains,

there are three possibilities.

Case 1

arr[0] = 0
target = 0

Possible subsets are

{}
{0}

Hence,

return 2.

------------------------------------------------------------

Case 2

target == 0

or

arr[0] == target

Exactly one subset exists.

Return 1.

------------------------------------------------------------

Case 3

Otherwise,

no subset exists.

Return 0.

--------------------------------------------------------------------
Recursive Relation
--------------------------------------------------------------------

Ways

=

Pick

+

Not Pick

--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N × K)

Each DP state is computed only once.

--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(N × K)

for the DP table

+

O(N)

auxiliary recursion stack.
*/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// Returns the number of subsets having sum = target
int countSubsequences(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {

    // Base Case
    if (ind == 0) {

        // Two possible subsets
        // {} and {0}
        if (target == 0 && arr[0] == 0)
            return 2;

        // Either choose nothing
        // or choose the first element
        if (target == 0 || arr[0] == target)
            return 1;

        // No valid subset
        return 0;
    }

    // Return previously computed answer
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Pick current element
    int pick = 0;

    if (target >= arr[ind])
        pick = countSubsequences(ind - 1, target - arr[ind], arr, dp);

    // Do not pick current element
    int notPick = countSubsequences(ind - 1, target, arr, dp);

    // Store and return answer
    return dp[ind][target] = (pick + notPick) % mod;
}

int findWays(vector<int> &arr, int k) {

    int n = arr.size();

    // DP Table
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return countSubsequences(n - 1, k, arr, dp);
}
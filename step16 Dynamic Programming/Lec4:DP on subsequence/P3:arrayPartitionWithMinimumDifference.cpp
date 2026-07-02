/*
====================================================================
QUESTION
====================================================================

You are given an array 'arr' containing 'n' non-negative integers.

Your task is to partition the array into two subsets such that the
absolute difference between the sum of the two subsets is minimum.

Each element must belong to exactly one subset.

The subsets do not need to be contiguous.

Return the minimum possible absolute difference between the two
subset sums.

--------------------------------------------------------------------

Example 1:

Input:
arr = [1, 2, 3, 4]

Output:
0

Explanation:

Subset 1 = {2, 3}
Subset 2 = {1, 4}

Sum of Subset 1 = 5
Sum of Subset 2 = 5

Absolute Difference = |5 - 5| = 0

--------------------------------------------------------------------

Example 2:

Input:
arr = [8, 6, 5]

Output:
3

Explanation:

Subset 1 = {8}
Subset 2 = {6, 5}

Sum of Subset 1 = 8
Sum of Subset 2 = 11

Absolute Difference = |11 - 8| = 3

====================================================================
INTUITION
====================================================================

Suppose,

Sum of first subset = S1

Sum of second subset = S2

The total sum of the array is

        Total = S1 + S2

Our goal is to minimize

        |S1 - S2|

Since,

        S2 = Total - S1

the expression becomes

        |(Total - S1) - S1|

        = |Total - 2 × S1|

Therefore, instead of trying every possible partition directly,
we only need to find all possible subset sums.

Once we know every achievable subset sum S1,

the other subset automatically has sum

        S2 = Total - S1

For every possible subset sum,

we compute

        |S2 - S1|

and keep the minimum answer.

--------------------------------------------------------------------

Why do we only check till Total / 2 ?

Consider,

Total = 20

Possible subset sums are

0, 1, 2, ..., 20

Suppose,

S1 = 16

Then,

S2 = 4

Difference = |16 - 4| = 12

Now consider

S1 = 4

S2 = 16

Difference = |4 - 16| = 12

Both produce the same answer.

Therefore, every subset sum greater than

Total / 2

has already been considered by its complementary subset.

Hence, it is sufficient to iterate only till

        Total / 2

which avoids unnecessary computation.

====================================================================
DP OBSERVATION
====================================================================

This problem is a direct extension of

        "Subset Sum Equal to K"

Instead of asking

"Can we make one particular target?"

we ask

"What are all the subset sums that are possible?"

The DP table stores whether a particular subset sum is achievable.

Finally,

we iterate over all achievable subset sums and calculate

        |(Total - Sum) - Sum|

The minimum of all these values is the answer.
*/


/*
====================================================================
SPACE OPTIMIZATION
====================================================================

Intuition:

This problem is an extension of the Subset Sum problem.

Instead of checking whether one particular target is achievable,
we want to know every possible subset sum that can be formed.

The DP state is:

prev[target]

which represents:

"Can we form the sum 'target' using the elements processed so far?"

---------------------------------------------------------------

Why Space Optimization?

In the tabulation solution,

the state was

        dp[ind][target]

Observe the transition carefully.

For every element,

dp[ind][target]

depends only on

1. dp[ind-1][target]
2. dp[ind-1][target-arr[ind]]

It never depends on any row before (ind-1).

Therefore,

instead of storing all N rows,

we only keep

1. Previous Row (prev)
2. Current Row (cur)

After computing one row,

simply assign

        prev = cur

and continue for the next element.

This reduces the space complexity from

O(N × TotalSum)

to

O(TotalSum).

---------------------------------------------------------------

Finding the Answer

After processing every element,

prev[target]

tells whether that subset sum is achievable.

Suppose,

Subset 1 Sum = S1

Subset 2 Sum = TotalSum - S1

Difference becomes

        |S2 - S1|

      = |(TotalSum - S1) - S1|

      = |TotalSum - 2 × S1|

We compute this value for every achievable subset sum
and keep the minimum.

---------------------------------------------------------------

Why iterate only till TotalSum / 2 ?

Suppose,

TotalSum = 20

If

S1 = 16

then

S2 = 4

Difference = |16 - 4| = 12

Now consider

S1 = 4

S2 = 16

Difference = |4 - 16| = 12

Both partitions produce the same answer.

Therefore,

checking subset sums beyond

TotalSum / 2

is unnecessary because their complementary subset
has already been considered.

---------------------------------------------------------------
Time Complexity

O(N × TotalSum)

where,

TotalSum = Sum of all array elements.

---------------------------------------------------------------
Space Complexity

O(TotalSum)

Only two 1D DP arrays are maintained.
*/

#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n) {

    // Calculate total sum of the array
    int total = 0;

    for (int i = 0; i < n; i++)
        total += arr[i];

    // Previous and current DP rows
    vector<bool> prev(total + 1, false);
    vector<bool> cur(total + 1, false);

    // Sum 0 is always possible
    prev[0] = true;
    cur[0] = true;

    // First element alone can form its own value
    if (arr[0] <= total)
        prev[arr[0]] = true;

    // Fill DP using space optimization
    for (int ind = 1; ind < n; ind++) {

        for (int target = 1; target <= total; target++) {

            // Pick current element
            bool pick = false;

            if (target >= arr[ind])
                pick = prev[target - arr[ind]];

            // Do not pick current element
            bool notPick = prev[target];

            // Store current state
            cur[target] = (pick || notPick);
        }

        // Move to next row
        prev = cur;
    }

    // Find minimum difference
    int mini = INT_MAX;

    for (int s1 = 0; s1 <= total / 2; s1++) {

        if (prev[s1]) {

            int s2 = total - s1;

            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}
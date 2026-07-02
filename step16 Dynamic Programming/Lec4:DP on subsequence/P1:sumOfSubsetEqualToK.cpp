
/*
------------------------------------------------------------
Recursion (Brute Force)
------------------------------------------------------------

Intuition:

For every element in the array, we have only two choices.

1. Pick the current element.
2. Do not pick the current element.

If we pick the current element,

the remaining target becomes

target - arr[ind]

and we move to the previous index.

If we do not pick the current element,

the target remains the same

and we again move to the previous index.

If either of these two choices can form the required sum,
then a valid subset exists.

------------------------------------------------------------
Base Cases
------------------------------------------------------------

1.

If target becomes 0,

it means we have successfully formed the required subset.

Return true.

------------------------------------------------------------

2.

If we reach the first element,

the only possible subset is the first element itself.

Return

arr[0] == target

------------------------------------------------------------
Recursive Relation
------------------------------------------------------------

f(ind, target)

=

Pick Current Element

OR

Do Not Pick Current Element

------------------------------------------------------------
Time Complexity
------------------------------------------------------------

O(2^N)

Each element has two choices:
Pick or Not Pick.

------------------------------------------------------------
Space Complexity
------------------------------------------------------------

O(N)

Auxiliary recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function
bool f(int ind, int target, vector<int> &arr) {

    // Target sum has been formed
    if (target == 0)
        return true;

    // Only one element is left
    if (ind == 0)
        return (arr[0] == target);

    // Do not pick current element
    bool notPick = f(ind - 1, target, arr);

    // Pick current element
    bool pick = false;

    if (target >= arr[ind])
        pick = f(ind - 1, target - arr[ind], arr);

    // Return true if any one choice succeeds
    return (pick || notPick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    return f(n - 1, k, arr);
}
/*
------------------------------------------------------------
Memoization
------------------------------------------------------------

Intuition:

The recursive solution solves the same subproblems multiple times.

Instead of solving the same state repeatedly, we store its answer.

DP State:

dp[ind][target]

represents:

Can we form the sum "target"
using elements from index 0 to ind?

If the state has already been computed,
simply return the stored answer.

Transition:

For every element, we have two choices.

1. Pick the current element.
2. Do not pick the current element.

If either choice returns true,
then a valid subset exists.

Time Complexity:
O(N × K)

where,
N = number of elements
K = target sum

Each state is computed only once.

Space Complexity:
O(N × K) for the DP table
+
O(N) auxiliary recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {

    // Target sum has been formed
    if (target == 0)
        return true;

    // Only one element is left
    if (ind == 0)
        return (arr[0] == target);

    // Return stored answer
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Do not pick current element
    bool notPick = f(ind - 1, target, arr, dp);

    // Pick current element
    bool pick = false;

    if (target >= arr[ind])
        pick = f(ind - 1, target - arr[ind], arr, dp);

    // Store and return answer
    return dp[ind][target] = (pick || notPick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    // DP table initialized with -1
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return f(n - 1, k, arr, dp);
}

/*

--------------------------------------------------------------------
Intuition
--------------------------------------------------------------------

In the recursive solution, for every element we had two choices:

1. Pick the current element.
2. Do not pick the current element.

The recursive state was

        f(ind, target)

which answered the question:

"Can we form target using elements from index 0 to ind?"

Instead of solving these states recursively again and again,
we store their answers in a DP table.

--------------------------------------------------------------------
DP State
--------------------------------------------------------------------

dp[i][target]

=

Can we form the sum "target"
using elements from index 0 to i ?

The value stored is

true  -> Possible

false -> Not Possible

--------------------------------------------------------------------
Base Cases
--------------------------------------------------------------------

1.

Target = 0

An empty subset always forms sum 0.

Therefore,

dp[i][0] = true

for every row.

------------------------------------------------------------

2.

For the first element,

if

arr[0] <= K

then

dp[0][arr[0]] = true

because using only the first element,
we can form exactly arr[0].

--------------------------------------------------------------------
Transition
--------------------------------------------------------------------

For every element,

we again have two choices.

------------------------------------------------------------

Case 1 : Pick

We can pick the current element only if

target >= arr[i]

Remaining target becomes

target - arr[i]

Therefore,

pick

=

dp[i-1][target-arr[i]]

------------------------------------------------------------

Case 2 : Not Pick

Ignore the current element.

Target remains the same.

Therefore,

notPick

=

dp[i-1][target]

------------------------------------------------------------

Current state becomes

dp[i][target]

=

pick OR notPick

--------------------------------------------------------------------
Filling Order
--------------------------------------------------------------------

The answer for row i depends only on row i-1.

Hence,

fill the DP table

from top to bottom

and

left to right.

--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N × K)

There are

N × K

states.

Each state takes O(1) time.

--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(N × K)

for the DP table.
*/

#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {

    // dp[i][target] = Can we form 'target'
    // using elements from index 0 to i ?
    vector<vector<bool>> dp(
        n,
        vector<bool>(k + 1, false)
    );

    // Sum 0 can always be formed
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // First element alone forms arr[0]
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    // Fill the DP table
    for (int i = 1; i < n; i++) {

        for (int target = 1; target <= k; target++) {

            // Pick current element
            bool pick = false;

            if (target >= arr[i])
                pick = dp[i - 1][target - arr[i]];

            // Do not pick current element
            bool notPick = dp[i - 1][target];

            // Store the answer
            dp[i][target] = (pick || notPick);
        }
    }

    // Final answer
    return dp[n - 1][k];
}

//Space Optimization
/*
--------------------------------------------------------------------
Intuition
--------------------------------------------------------------------

In the tabulation solution, we used a DP table

        dp[index][target]

where

dp[index][target]

represented

"Can we form the sum 'target' using elements from index 0 to index?"

Now observe the transition carefully.

For every state,

dp[index][target]

depends only on the previous row:

1. dp[index-1][target]
2. dp[index-1][target-arr[index]]

It never depends on older rows.

Therefore, storing all N rows is unnecessary.

We only need:

Previous Row

and

Current Row.

Hence,

dp[index-1][...]

can be replaced by

prev[...]

and

dp[index][...]

can be replaced by

cur[...]

After finishing one row,

simply assign

prev = cur

and continue for the next index.

This reduces the space complexity from

O(N × K)

to

O(K).

--------------------------------------------------------------------
Approach
--------------------------------------------------------------------

1. Create two 1D arrays:
      • prev → previous row.
      • cur  → current row.

2. Initialize:
      prev[0] = true
      cur[0] = true

   because sum 0 is always possible.

3. If the first element is within the target,
   mark

      prev[arr[0]] = true

4. Traverse every remaining element.

5. For every target:
      • Pick the current element.
      • Do not pick the current element.
      • Store the result in cur[target].

6. After completing one row,
   copy

      prev = cur

7. The answer is stored in

      prev[k]

--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N × K)

where,

N = number of elements

K = target sum

--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(K)

Only two arrays of size (K + 1) are maintained.
*/

#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {

    // Previous DP row
    vector<bool> prev(k + 1, false);

    // Current DP row
    vector<bool> cur(k + 1, false);

    // Sum 0 is always possible
    prev[0] = true;
    cur[0] = true;

    // First element alone forms arr[0]
    if (arr[0] <= k)
        prev[arr[0]] = true;

    // Traverse all remaining elements
    for (int i = 1; i < n; i++) {

        for (int target = 1; target <= k; target++) {

            // Pick current element
            bool pick = false;

            if (target >= arr[i])
                pick = prev[target - arr[i]];

            // Do not pick current element
            bool notPick = prev[target];

            // Store current state
            cur[target] = (pick || notPick);
        }

        // Current row becomes previous row
        prev = cur;
    }

    return prev[k];
}
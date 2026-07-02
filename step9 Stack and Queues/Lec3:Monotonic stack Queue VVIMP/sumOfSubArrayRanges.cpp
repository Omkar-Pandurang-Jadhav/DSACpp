/*
Question:
You are given an integer array nums.

The range of a subarray is defined as

        Maximum Element - Minimum Element

Return the sum of the ranges of every contiguous subarray.

Example 1:
Input:
nums = [1,2,3]

Output:
4

Explanation:
Subarrays:

[1]       Range = 0
[2]       Range = 0
[3]       Range = 0
[1,2]     Range = 1
[2,3]     Range = 1
[1,2,3]   Range = 2

Total = 4

Example 2:
Input:
nums = [1,3,3]

Output:
4

--------------------------------------------------------------------
Intuition
--------------------------------------------------------------------

A brute-force solution generates every subarray, finds its minimum and
maximum, and adds

        Maximum - Minimum

This requires O(N²) or O(N³).

Instead, observe the following identity:

For every subarray,

        Range = Maximum - Minimum

Therefore,

Sum of all ranges

=

Σ(Maximum - Minimum)

Using the distributive property,

=

Σ(Maximum) - Σ(Minimum)

So the problem becomes two independent problems:

1. Find the sum of maximums of all subarrays.
2. Find the sum of minimums of all subarrays.

Finally,

Answer

=

Sum of Maximums
-
Sum of Minimums

--------------------------------------------------------------------
How do we compute the Sum of Minimums?
--------------------------------------------------------------------

Instead of finding the minimum of every subarray,
reverse the thinking.

Ask:

"In how many subarrays does nums[i] become the minimum?"

If nums[i] is the minimum in K subarrays,

its contribution is

        K × nums[i]

To calculate K,

we find

Previous Smaller Element

and

Next Smaller Element.

These two indices define the region where nums[i]
remains the smallest element.

Let

left

=

number of choices for the starting index

=

i - PreviousSmaller

right

=

number of choices for the ending index

=

NextSmaller - i

Every starting position can combine with every ending position.

Therefore,

Number of subarrays

=

left × right

Contribution

=

left × right × nums[i]

--------------------------------------------------------------------
How do we compute the Sum of Maximums?
--------------------------------------------------------------------

Exactly the same idea.

Instead of Previous Smaller and Next Smaller,

use

Previous Greater

and

Next Greater.

Contribution becomes

left × right × nums[i]

where nums[i] acts as the maximum.

--------------------------------------------------------------------
Handling Duplicate Elements
--------------------------------------------------------------------

For Minimum:

Previous Smaller

uses

<

Next Smaller

uses

<=

For Maximum:

Previous Greater

uses

>

Next Greater

uses

>=

This tie-breaking ensures every subarray is counted exactly once.

--------------------------------------------------------------------
Approach
--------------------------------------------------------------------

1. Compute the Next Smaller Element for every index.
2. Compute the Previous Smaller Element.
3. Compute the Next Greater Element.
4. Compute the Previous Greater Element.
5. For every element:
      • Calculate its contribution as the minimum.
      • Calculate its contribution as the maximum.
6. Add

      Maximum Contribution - Minimum Contribution

7. Return the final answer.

--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N)

Each monotonic stack traversal is O(N).

Four traversals are performed.

--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(N)

for storing the four helper arrays and the stacks.
*/

class Solution {
public:

    // Returns the index of the Next Smaller Element
    vector<int> nextSmallestElement(vector<int> arr) {

        int n = arr.size();

        vector<int> ans(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();

            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Returns the index of the Previous Smaller Element
    vector<int> prevSmallestElement(vector<int> arr) {

        int n = arr.size();

        vector<int> ans(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Returns the index of the Next Greater Element
    vector<int> nextGreatestElement(vector<int> arr) {

        int n = arr.size();

        vector<int> ans(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[i] >= arr[st.top()])
                st.pop();

            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Returns the index of the Previous Greater Element
    vector<int> prevGreatestElement(vector<int> arr) {

        int n = arr.size();

        vector<int> ans(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[i] > arr[st.top()])
                st.pop();

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {

        // Next Smaller Element indices
        vector<int> nextSE = nextSmallestElement(nums);

        // Previous Smaller Element indices
        vector<int> prevSEE = prevSmallestElement(nums);

        // Next Greater Element indices
        vector<int> nextGE = nextGreatestElement(nums);

        // Previous Greater Element indices
        vector<int> prevGEE = prevGreatestElement(nums);

        long long sum = 0;

        // Calculate contribution of every element
        for (int i = 0; i < nums.size(); i++) {

            // Number of left choices where nums[i] is minimum
            long long leftS = i - prevSEE[i];

            // Number of right choices where nums[i] is minimum
            long long rightS = nextSE[i] - i;

            // Number of left choices where nums[i] is maximum
            long long leftG = i - prevGEE[i];

            // Number of right choices where nums[i] is maximum
            long long rightG = nextGE[i] - i;

            // Contribution as minimum
            long long small = leftS * rightS * nums[i];

            // Contribution as maximum
            long long great = leftG * rightG * nums[i];

            // Add contribution to final answer
            sum += great - small;
        }

        return sum;
    }
};
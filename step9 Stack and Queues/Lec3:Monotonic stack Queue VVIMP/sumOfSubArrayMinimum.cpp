/*
Question:
Given an integer array arr, return the sum of the minimum element of
every contiguous subarray.

Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:
Input:
arr = [3,1,2,4]

Output:
17

Explanation:
Subarrays:
[3], [1], [2], [4], [3,1], [1,2], [2,4],
[3,1,2], [1,2,4], [3,1,2,4]

Minimums:
3,1,2,4,1,1,2,1,1,1

Sum = 17

Example 2:
Input:
arr = [11,81,94,43,3]

Output:
444

--------------------------------------------------------------------
Intuition:
--------------------------------------------------------------------

Instead of generating every subarray and finding its minimum,
we reverse the thinking.

Rather than asking:

"For every subarray, what is its minimum?"

we ask:

"For every element, in how many subarrays does this element become
the minimum?"

If we know that an element contributes as the minimum in K subarrays,
then its total contribution is simply

        K × arr[i]

The final answer is the sum of the contribution of every element.

--------------------------------------------------------------------
Why do we calculate Previous Smaller and Next Smaller?
--------------------------------------------------------------------

Consider an element

        arr[i]

We want to know how far we can expand this element towards the left
and towards the right while still keeping it as the minimum.

For this we need

1. Previous Smaller Element
   The closest smaller element on the left.

2. Next Smaller Element
   The closest smaller (or equal) element on the right.

These two elements act as boundaries.

The current element can only remain the minimum between these
boundaries.

--------------------------------------------------------------------
Why is

left = i - previousSmaller

?
--------------------------------------------------------------------

Suppose

Index : 0 1 2 3 4
Array : 5 4 2 6 7
            ↑
            i

Previous Smaller = -1

Then the left boundary choices are

2
4,2
5,4,2

Total choices = 3

which equals

i - previousSmaller

= 2 - (-1)
= 3

--------------------------------------------------------------------
Why is

right = nextSmaller - i

?
--------------------------------------------------------------------

Suppose

Index : 0 1 2 3 4
Array : 5 4 2 6 7
            ↑
            i

Next Smaller = 5 (doesn't exist)

Right boundary choices are

2
2,6
2,6,7

Total choices = 3

which equals

nextSmaller - i

= 5 - 2
= 3

--------------------------------------------------------------------
Why do we multiply left × right?
--------------------------------------------------------------------

Suppose

Left choices = 3

Right choices = 4

Every left choice can combine with every right choice.

For example

Left choices

A
B
C

Right choices

1
2
3
4

Possible subarrays

A1 A2 A3 A4
B1 B2 B3 B4
C1 C2 C3 C4

Total

3 × 4 = 12

Hence,

Number of subarrays where arr[i] is the minimum

=

left × right

Therefore,

Contribution of arr[i]

=

left × right × arr[i]

Adding the contribution of every element gives the final answer.

--------------------------------------------------------------------
Handling Duplicate Elements
--------------------------------------------------------------------

For duplicates, we use

Previous Smaller  -> strictly smaller (<)

Next Smaller      -> smaller or equal (<=)

This ensures every subarray is counted exactly once and prevents
double counting.

Approach:
1. Compute the Previous Smaller Element for every index.
2. Compute the Next Smaller Element for every index.
3. For every element:
      left = i - previousSmaller
      right = nextSmaller - i
4. Number of subarrays where arr[i] is the minimum is

      left × right

5. Add

      left × right × arr[i]

   to the answer.
6. Return the answer modulo 10^9 + 7.

Time Complexity:
O(N)

where,
N = size of the array.

Each element is pushed and popped from the stack at most once.

Space Complexity:
O(N)

for storing the Previous Smaller array,
Next Smaller array,
and the monotonic stack.
*/

class Solution {
public:

    // Returns the index of the Next Smaller Element
    vector<int> nextSmallestElement(vector<int> arr) {

        vector<int> ans(arr.size());

        // Monotonic increasing stack storing indices
        stack<int> st;

        // Traverse from right to left
        for (int i = arr.size() - 1; i >= 0; i--) {

            // Remove all elements greater than or equal
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();

            // No smaller element exists
            if (st.empty())
                ans[i] = arr.size();

            // Next Smaller Element index
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    // Returns the index of the Previous Smaller Element
    vector<int> previousSmallestElement(vector<int> arr) {

        vector<int> ans(arr.size());

        // Monotonic increasing stack storing indices
        stack<int> st;

        // Traverse from left to right
        for (int i = 0; i < arr.size(); i++) {

            // Remove all strictly greater elements
            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();

            // No previous smaller element exists
            if (st.empty())
                ans[i] = -1;

            // Previous Smaller Element index
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        // Next Smaller Element indices
        vector<int> nextSE = nextSmallestElement(arr);

        // Previous Smaller Element indices
        vector<int> prevSEE = previousSmallestElement(arr);

        long long mod = 1e9 + 7;

        // Stores the final answer
        long long total = 0;

        // Calculate the contribution of every element
        for (int i = 0; i < arr.size(); i++) {

            // Number of choices on the left
            long long left = i - prevSEE[i];

            // Number of choices on the right
            long long right = nextSE[i] - i;

            // Contribution of current element
            total = (total +
                    (((left * right) % mod) * arr[i]) % mod) % mod;
        }

        return total;
    }
};
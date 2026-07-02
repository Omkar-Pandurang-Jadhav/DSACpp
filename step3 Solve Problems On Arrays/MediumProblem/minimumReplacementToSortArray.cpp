/*
Question:
You are given a 0-indexed integer array nums.

In one operation, you can replace any element of the array with any
two positive integers whose sum is equal to that element.

Return the minimum number of operations required to make the array
sorted in non-decreasing order.

Example 1:
Input: nums = [3,9,3]
Output: 2

Explanation:
9 is replaced by (3,6), then 6 is replaced by (3,3),
resulting in a sorted array.

Example 2:
Input: nums = [1,2,3,4,5]
Output: 0

Approach:
1. Traverse the array from right to left.
2. Let 'last' denote the maximum value that the current element is
   allowed to have so that the array remains non-decreasing.
3. If nums[i] <= last, no replacement is required.
   Simply update last = nums[i].
4. Otherwise, nums[i] must be divided into multiple parts.
5. Every part must be less than or equal to 'last'.
6. Let the number of required parts be:

      parts = ceil(nums[i] / last)

   This is the minimum number of parts such that every part is
   less than or equal to 'last'.
7. Replacing one element with 'parts' elements requires

      parts - 1

   replacement operations.
8. Add (parts - 1) to the answer.
9. After splitting, the smallest possible maximum value of every part
   becomes

      nums[i] / parts

   (integer division)

   Update 'last' with this value because it becomes the new upper
   bound for the elements on the left.
10. Continue until the beginning of the array.

Why Traverse From Right to Left?
The last element never needs to change because nothing comes after it.

While processing an element, we already know the maximum value it is
allowed to take (stored in 'last') so that the suffix remains sorted.

Hence, every decision depends on the element to its right, making
right-to-left traversal the natural greedy approach.

Mathematical Proof:

Suppose

Current element = X
Maximum allowed value = last

We want to split X into the minimum number of parts.

Let the number of parts be k.

Since every part must satisfy

part <= last

the total sum of k parts can be at most

k × last

Therefore,

k × last >= X

which implies

k >= X / last

Since k must be an integer,

k = ceil(X / last)

Thus,

parts = ceil(nums[i] / last)

is the minimum number of parts required.

Each replacement operation increases the number of elements by exactly 1.

Initially we have

1 element

After one replacement

2 elements

After two replacements

3 elements

...

To obtain

parts elements,

we need exactly

parts - 1

operations.

Finally, after splitting into 'parts' pieces, the largest possible
minimum value that every part can have is

nums[i] / parts

(integer division)

This value becomes the new upper limit ('last') for processing the
remaining elements on the left.

Time Complexity:
O(N)

where,
N = size of the array.

Space Complexity:
O(1)

since only a few variables are used.
*/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        // Stores the total number of replacement operations
        long long cnt = 0;

        int n = nums.size();

        // Maximum value allowed for the current element
        int last = nums[n - 1];

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {

            // Current element must be split
            if (nums[i] > last) {

                // Minimum number of parts required
                int p = nums[i] / last;

                // Compute ceiling division
                if (nums[i] % last != 0)
                    p += 1;

                // Number of replacement operations
                cnt += p - 1;

                // New maximum allowed value for previous elements
                last = nums[i] / p;
            }

            // No replacement required
            else {

                last = nums[i];
            }
        }

        return cnt;
    }
};
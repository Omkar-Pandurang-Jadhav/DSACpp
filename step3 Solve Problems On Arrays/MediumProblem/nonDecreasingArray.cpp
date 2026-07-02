/*
Question:
Given an integer array nums, determine whether it can become
non-decreasing by modifying at most one element.

An array is considered non-decreasing if for every index i,
nums[i] <= nums[i + 1].

Return true if it is possible to make the array non-decreasing
by modifying at most one element, otherwise return false.

Example 1:
Input: nums = [4,2,3]
Output: true

Explanation:
Modify 4 to 2 (or any value less than or equal to 2), resulting in
[2,2,3], which is non-decreasing.

Example 2:
Input: nums = [4,2,1]
Output: false

Explanation:
More than one modification is required to make the array
non-decreasing.

Approach:
1. Traverse the array from left to right and compare every element
   with its next element.
2. If nums[i] <= nums[i + 1], the current pair is already in the
   correct order, so continue to the next pair.
3. If nums[i] > nums[i + 1], a violation of the non-decreasing
   property is found.
4. Since only one modification is allowed, maintain a boolean variable
   'changed' to keep track of whether a modification has already been made.
5. If another violation is encountered after one modification has
   already been used, immediately return false.
6. Otherwise, decide which element should be modified:
   - If the current element is the first element of the array
     (i == 0), or if nums[i + 1] is greater than or equal to
     nums[i - 1], then it is safe to decrease nums[i] so that it
     becomes equal to nums[i + 1]. This preserves the order with the
     previous element as well.
   - Otherwise, increasing nums[i + 1] is the better choice because
     decreasing nums[i] would break the ordering with nums[i - 1].
7. Mark that one modification has been used and continue checking the
   remaining array.
8. If the traversal finishes without requiring more than one
   modification, return true.

Time Complexity:
O(N)

where,
N = size of the array

Space Complexity:
O(1)

since only a boolean variable is used apart from the input array.
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int n = nums.size();

        // Indicates whether one modification has already been performed
        bool changed = false;

        // Traverse the array and check every adjacent pair
        for (int i = 0; i < n - 1; i++) {

            // Current pair is already in non-decreasing order
            if (nums[i] <= nums[i + 1])
                continue;

            // More than one modification would be required
            else if (changed)
                return false;

            // Safe to modify the current element
            if (i == 0 || nums[i + 1] >= nums[i - 1]) {

                // Lower the current element
                nums[i] = nums[i + 1];
                changed = true;
            }

            // Modify the next element instead
            else {

                // Increase the next element
                nums[i + 1] = nums[i];
                changed = true;
            }
        }

        return true;
    }
};
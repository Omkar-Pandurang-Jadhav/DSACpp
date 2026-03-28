/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example,
 the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        // Binary search on rotated sorted array
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Case 1: Only one element left
            if (low == high) return nums[low];

            // Case 2: The subarray [low...high] is already sorted
            // then nums[low] is the smallest
            if (nums[low] <= nums[mid] && nums[mid] <= nums[high]) 
                return nums[low];

            // Case 3: Left half [low...mid] is sorted
            // so min must be in right half
            if (nums[low] <= nums[mid]) {
                low = mid + 1;
            }
            // Case 4: Right half [mid...high] is sorted
            // so min could be mid or in left half
            else if (nums[mid] <= nums[high]) {
                high = mid;   // NOTE: use high = mid (not mid-1), since mid itself could be min
            }
        }

        // Fallback (array not rotated, min is at index 0)
        return nums[0];
    }
};

/*
----------------------------------------------------
Approach:
- The array is a rotated sorted array.
- Use binary search to find the pivot (smallest element).
- At each step:
    1. If array between low and high is sorted, nums[low] is the answer.
    2. If left half is sorted, the min must lie in the right half → low = mid + 1.
    3. If right half is sorted, the min must lie in left half or be mid → high = mid.
- Continue until low == high, which will point to the minimum element.

Time Complexity: O(log n)   (binary search halves the search space each step)
Space Complexity: O(1)      (only a few variables used)
----------------------------------------------------
*/

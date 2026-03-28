/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

 */


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;

        // Binary Search to find position
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) 
                return mid;         // target found
            else if (nums[mid] > target) 
                high = mid - 1;     // search left half
            else 
                low = mid + 1;      // search right half
        }

        // if not found, insertion point will be high + 1 (same as low here)
        return high + 1;
    }
};

/*
Time Complexity: O(log n)  -> binary search halves the array each step
Space Complexity: O(1)     -> constant extra space
*/

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

*/

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (findFirst) 
                    high = mid - 1;  // search left side
                else 
                    low = mid + 1;   // search right side
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last  = binarySearch(nums, target, false);
        return {first, last};
    }
};

/*
Time Complexity: O(log n)   -> binary search twice
Space Complexity: O(1)      -> constant space
*/

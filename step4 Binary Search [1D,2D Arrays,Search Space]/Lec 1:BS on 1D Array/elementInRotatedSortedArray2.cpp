class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // Case: duplicates make it unclear which half is sorted
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // search left half
                } else {
                    low = mid + 1;  // search right half
                }
            }
            // Otherwise right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // search right half
                } else {
                    high = mid - 1; // search left half
                }
            }
        }

        return false; // not found
    }
};

/*
Time Complexity: O(log n) in average case,
                 O(n) in worst case (when duplicates force linear scan)
Space Complexity: O(1)
*/

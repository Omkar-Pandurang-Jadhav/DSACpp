class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        // Binary Search loop
        while (low <= high) {
            int mid = low + (high - low) / 2; // to avoid overflow

            if (nums[mid] == target) 
                return mid;          // target found
            else if (nums[mid] > target) 
                high = mid - 1;      // search left side
            else 
                low = mid + 1;       // search right side
        }

        return -1; // target not found
    }
};

/*
Time Complexity: O(log n)  -> because the search space is halved each iteration
Space Complexity: O(1)     -> only uses a few extra variables
*/

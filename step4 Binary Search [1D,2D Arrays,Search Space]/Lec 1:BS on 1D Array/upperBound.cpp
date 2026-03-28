/*
Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

Examples :

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 6
Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7*/



class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n; // default = n (if all elements <= target)

        // Binary Search for upper bound
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target) {
                ans = mid;       // possible upper bound
                high = mid - 1;  // search left half
            }
            else {
                low = mid + 1;   // search right half
            }
        }

        return ans; // index of first element > target, or n if none
    }
};

/*
Time Complexity: O(log n)  -> because search space is halved each step
Space Complexity: O(1)     -> uses only a few extra variables
*/

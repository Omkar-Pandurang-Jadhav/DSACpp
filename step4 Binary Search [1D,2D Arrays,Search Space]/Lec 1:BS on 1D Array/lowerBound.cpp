
/*Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. 
The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

Examples :

Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 4
Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7
Explanation: As no element in arr[] is greater than 100, return the length of array.*/

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n; // default = n (if all elements < target)

        // Binary Search for lower bound
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid;       // possible lower bound
                high = mid - 1;  // search left half
            }
            else {
                low = mid + 1;   // search right half
            }
        }

        return ans; // index of first element >= target, or n if none
    }
};

/*
Time Complexity: O(log n)  -> halves the search space each step
Space Complexity: O(1)     -> uses only a few variables
*/

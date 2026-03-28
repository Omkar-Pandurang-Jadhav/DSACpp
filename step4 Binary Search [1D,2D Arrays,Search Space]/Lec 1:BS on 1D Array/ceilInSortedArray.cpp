/*
Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is 
greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
Output: 2
Explanation: Smallest number greater than 5 is 8, whose index is 2.

Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 20
Output: -1
Explanation: No element greater than 20 is found. So output is -1.

Input: arr[] = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output: 0
Explanation: Smallest number greater than 0 is 1, whose indices are 0 and 1. The index of the first occurrence is 0.
*/

// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = -1; // default = -1 (if all elements < x)

        // Binary Search for ceil
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ans = mid;        // possible ceil
                high = mid - 1;   // try to find smaller index on left
            }
            else {
                low = mid + 1;    // search right side
            }
        }

        return ans; // index of smallest element >= x, or -1 if none
    }
};

/*
Time Complexity: O(log n)  -> search space reduces by half each step
Space Complexity: O(1)     -> only constant variables used
*/

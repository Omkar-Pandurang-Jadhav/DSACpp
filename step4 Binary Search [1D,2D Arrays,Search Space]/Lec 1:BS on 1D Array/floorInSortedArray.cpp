/*
Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x.
 This element is called the floor of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 11
Output: 4
Explanation: Largest Number less than or equal to 11 is 10, whose indices are 3 and 4. The index of last occurrence is 4.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
Output: -1
Explanation: No element less than or equal to 0 is found. So, output is -1.*/


class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = -1; // default = -1 (if all elements > x)

        // Binary Search for floor
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                ans = mid;        // possible floor
                low = mid + 1;    // search right half for larger floor
            }
            else {
                high = mid - 1;   // search left half
            }
        }

        return ans; // index of greatest element <= x, or -1 if none
    }
};

/*
Time Complexity: O(log n)  -> binary search halves the search space
Space Complexity: O(1)     -> only a few variables used
*/

/*
Given an array arr[] of integers and an integer k, select k elements from the array such that the minimum absolute
 difference between any two of the selected elements is maximized. Return this maximum possible minimum difference.

Examples:

Input: arr[] = [2, 6, 2, 5], k = 3
Output: 1
Explanation: 3 elements out of 4 elements are to be selected with a minimum difference as large as possible. Selecting 2, 2, 5 
will result in minimum difference as 0. Selecting 2, 5, 6 will result in minimum difference as 6 - 5 = 1.

Input: arr[] = [1, 4, 9, 0, 2, 13, 3], k = 4
Output: 4
Explanation: Selecting 0, 4, 9, 13 will result in minimum difference of 4, which is the largest minimum difference possible.*/





class Solution {
  public:
    /*
    -------------------------------------------
    Approach:
    1. Sort the array because we want elements in increasing order 
       to check possible placements with minimum difference.
    2. We will apply Binary Search on the "answer space":
       - Low = 1  (minimum possible difference)
       - High = max(arr) - min(arr) (maximum possible difference)
    3. For each mid (candidate minimum difference), check if we can 
       select at least 'k' elements such that each selected element 
       differs from the previously selected by at least 'mid'.
       -> This is checked using the helper function `canFormGroup`.
    4. If possible for 'mid', store it in answer and try for a bigger 
       difference (low = mid+1).
       Otherwise, reduce the search space (high = mid-1).
    5. Return the maximum feasible minimum difference.

    -------------------------------------------
    Time Complexity:
    - Sorting: O(N log N)
    - Binary Search over range (0 .. max-min): O(log(max-min))
    - Each feasibility check: O(N)
    Total: O(N log N + N log(max-min))

    Space Complexity:
    - O(1) extra space (in-place checking)
    -------------------------------------------
    */

    // Helper function to check if we can form group of k elements
    // such that each pair of consecutive chosen elements has 
    // at least 'dist' difference
    bool canFormGroup(vector<int> &arr, int k, int dist) {
        int cnt = 1;           // first element is always chosen
        int last = arr[0];     // keep track of last chosen element
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            if (arr[i] - last >= dist) {
                cnt++;
                last = arr[i];
                if (cnt >= k) return true; // if already selected k
            }
        }
        return false;  // not possible with this 'dist'
    }

    int maxMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());  // Step 1: Sort the array

        int low = 1;                            // smallest possible min diff
        int high = arr[n-1] - arr[0];           // largest possible min diff
        int ans = 0;

        // Step 2: Binary search on the possible difference
        while (low <= high) {
            int mid = low + (high - low) / 2;   // candidate min diff

            if (canFormGroup(arr, k, mid)) {
                ans = mid;        // feasible → try for larger distance
                low = mid + 1;
            } else {
                high = mid - 1;   // not feasible → reduce distance
            }
        }
        return ans;  // maximum feasible minimum difference
    }
};

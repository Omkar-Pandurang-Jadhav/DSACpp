/*
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in 
non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s.
 If no such row exists, return -1.

Note:

    The array follows 0-based indexing.
    The number of rows and columns in the array are denoted by n and m respectively.

Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.

Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.*/


// ✅ Problem: Row with maximum 1s in a binary matrix
// Each row of the matrix is sorted (0s followed by 1s).

// ✅ Approach:
// 1. We need to find the row that has the maximum number of 1s.
// 2. Since rows are sorted, we can use Binary Search to find the first occurrence of `1` in each row.
// 3. If we know the index of the first `1`, then count of 1s = (n - index).
// 4. Keep track of the row with the maximum count of 1s.
// 5. If no 1s are present in the matrix, return -1.
//
// 🔹 Binary Search (countOne):
//   - If nums[mid] == 1 → Move left (to find earlier 1).
//   - Else (nums[mid] == 0) → Move right.
//
// ✅ Time Complexity: O(m log n)
//    - m = number of rows
//    - n = number of columns
//    - Binary search on each row → O(log n) per row.
// ✅ Space Complexity: O(1)
//    - Only constant extra space used.

class Solution {
  public:
    // Function to count number of 1s in a row using Binary Search
    int countOne(vector<int> &nums, int n) {
        int low = 0, high = n - 1;
        int firstIndex = -1;

        // Binary search to find first occurrence of 1
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == 1) {
                firstIndex = mid;   // potential answer
                high = mid - 1;     // try to find earlier 1
            } else {
                low = mid + 1;      // move right
            }
        }

        // If no 1 found
        if (firstIndex == -1) return 0;
        return n - firstIndex; // count of 1s = total length - index of first 1
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int ans = 0;       // max number of 1s found
        int index = -1;    // row index with max 1s

        for (int i = 0; i < arr.size(); i++) {
            int cnt = countOne(arr[i], arr[i].size());
            
            if (cnt > ans) {
                ans = cnt;
                index = i;
            }
        }

        return index;
    }
};

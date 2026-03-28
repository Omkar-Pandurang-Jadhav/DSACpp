
/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:

Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers*/


/*
Approach:
----------
We are solving the "Find Peak Element in a 2D Matrix" problem.
A peak element in a 2D matrix is an element that is strictly greater than its top, bottom, left, and right neighbors.

Steps:
1. Perform Binary Search on rows.
2. For each mid row, find the index of the maximum element in that row.
3. Compare this max element with the elements in the row above and below:
   - If the above element is greater, move search space to upper half.
   - If the below element is greater, move search space to lower half.
   - Otherwise, the current element is a peak → return its position.
4. Handle boundary cases when `mid` is the first or last row.

Why it works:
- At each step, binary search reduces the number of rows to check.
- The maximum element in a row is guaranteed to lead us toward a peak.

Time Complexity:
-----------------
O(n * log m)  
- For each binary search step, finding max in a row takes O(m).  
- Binary search runs in O(log n).  
- Overall: O(m * log n).

Space Complexity:
------------------
O(1) → no extra space used except variables.
*/

class Solution {
public:
    // Helper function to find the index of the maximum element in a row
    int maximumElementInRow(vector<int> &row, int m) {
        int maxIdx = 0;
        for (int i = 1; i < m; i++) {
            if (row[i] > row[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Find maximum element in mid row
            int maxCol = maximumElementInRow(mat[mid], m);

            int up = mid - 1;
            int down = mid + 1;

            // Compare with up and down neighbors
            if (up >= 0 && mat[up][maxCol] > mat[mid][maxCol]) {
                high = mid - 1; // move upward
            }
            else if (down < n && mat[down][maxCol] > mat[mid][maxCol]) {
                low = mid + 1; // move downward
            }
            else {
                // Peak found
                return {mid, maxCol};
            }
        }

        return {-1, -1}; // fallback (should never reach here)
    }
};




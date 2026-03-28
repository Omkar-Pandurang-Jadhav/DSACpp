/*
You are given a 2D matrix mat[][] of size n x m that was initially filled in the following manner:

    Each row is sorted in increasing order from left to right.
    The first element of every row is greater than the last element of the previous row.

This implies that if the matrix is flattened row-wise, it forms a strictly sorted 1D array.
Later, this sorted 1D array was rotated at some unknown pivot. The rotated array was then written back into the matrix
 row-wise to form the current matrix.

Given such a matrix mat[][] and an integer x, determine whether x exists in the matrix.

Examples:

Input: x = 3,
mat[][] = [[7, 8, 9, 10],           
          [11, 12, 13, 1],
          [2, 3, 4, 5]] 
Output: true
Explanation: 3 is located at the 3rd row and 2nd column.

Input: x = 10,
mat[][] = [[6, 7, 8],                         
          [9, 1, 2],
          [3, 4, 5]]
Output: false
Explanation: The value 10 does not exist in the matrix.*/


class Solution {
  public:
    // Approach:
    // We treat the 2D matrix as a sorted 1D array of size n*m
    // Perform normal binary search on this virtual array
    // Map index -> (row = mid/m , col = mid%m) to access elements
    // Compare with target and shrink search space accordingly

    // Time Complexity: O(log(n*m)) = O(logN), where N = total elements
    // Space Complexity: O(1), as we use only constant extra space

    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();          // number of rows
        int m = mat[0].size();       // number of columns

        int low = 0;                 // starting index in virtual 1D array
        int high = n * m - 1;        // ending index in virtual 1D array

        // Binary search loop
        while (low <= high) {
            int mid = low + (high - low) / 2;   // calculate mid safely

            int row = mid / m;      // map mid to row index
            int col = mid % m;      // map mid to column index

            if (mat[row][col] == x) return true;  // target found
            else if (mat[row][col] < x) 
                low = mid + 1;      // target is in right half
            else 
                high = mid - 1;     // target is in left half
        }

        return false;   // target not found
    }
};

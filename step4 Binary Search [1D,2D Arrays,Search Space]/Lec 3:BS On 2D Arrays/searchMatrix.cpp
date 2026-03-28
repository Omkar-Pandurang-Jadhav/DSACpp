/*

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

 

Example 1:

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

*/

/*
Problem: Search in a row-wise and column-wise sorted matrix
LeetCode: 240. Search a 2D Matrix II
GFG: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/

---------------------------------------------------------
Approach:
- We know each row is sorted left→right and each column is sorted top→bottom.
- Start from the top-right corner element (matrix[0][m-1]).
- At each step:
    * If matrix[row][col] == target → Found → return true
    * If matrix[row][col] > target → move left (col--)
    * If matrix[row][col] < target → move down (row++)
- Continue until row < n and col >= 0.
- If loop ends, target is not present.

---------------------------------------------------------
Time Complexity: O(n + m)
    - At most we move n steps down + m steps left.
    - More efficient than row-wise binary search O(n log m).
Space Complexity: O(1)
    - Only uses a few variables.

---------------------------------------------------------
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns

        int row = 0;                  // start from top-right
        int col = m - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) 
                return true;          // target found
            else if (matrix[row][col] > target) 
                col--;                // move left
            else 
                row++;                // move down
        }

        return false; // target not found
    }
};

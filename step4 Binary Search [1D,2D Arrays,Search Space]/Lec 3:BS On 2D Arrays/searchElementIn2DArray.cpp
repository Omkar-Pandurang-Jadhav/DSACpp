/*
You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

/*
Approach:
---------
We are given a matrix where:
1. Each row is sorted in non-decreasing order.
2. The first element of each row is greater than the last element of the previous row.

That means the entire matrix can be viewed as a sorted 1D array of size n*m.

Steps:
1. Use binary search on the range [0, n*m - 1].
2. Convert the mid index into (row, col) using:
       row = mid / m
       col = mid % m
3. Compare matrix[row][col] with target:
   - If equal → return true
   - If smaller → search in right half
   - If larger → search in left half
4. If not found, return false.

Time Complexity:
----------------
O(log(n*m))  → binary search over n*m elements

Space Complexity:
-----------------
O(1) → only variables for binary search
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // number of rows
        int m = matrix[0].size();    // number of columns

        int low = 0;
        int high = n * m - 1;        // total elements - 1

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Convert mid into (row, col)
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) 
                return true;         // found target
            else if (matrix[row][col] < target) 
                low = mid + 1;       // search right half
            else 
                high = mid - 1;      // search left half
        }
        return false;  // target not found
    }
};

/*
Question:
You are given an m x n matrix grid consisting of non-negative integers.

In one operation, you can increment the value of any cell by 1.

Return the minimum number of operations required to make every column
of the matrix strictly increasing.

A column is strictly increasing if for every valid row index,
grid[i][j] < grid[i + 1][j].

Example 1:
Input: grid = [[3,2],[1,3],[3,4],[0,1]]
Output: 15

Example 2:
Input: grid = [[3,2,1],[2,1,0],[1,2,3]]
Output: 12

Approach:
1. Traverse each column of the matrix independently since operations
   performed on one column do not affect any other column.
2. For every column, compare each element with the element directly
   below it.
3. If the lower element is already greater than the upper element,
   no operation is required.
4. Otherwise, calculate the minimum number of increments required to
   make the lower element exactly one greater than the upper element.
5. Add these increments to the total answer.
6. Update the lower element with its new value after incrementing,
   since subsequent comparisons in the same column must use the
   modified value.
7. Continue this process for all rows and all columns.
8. Return the total number of operations performed.

Time Complexity:
O(M × N)

where,
M = number of rows
N = number of columns

Space Complexity:
O(1)

since the matrix is modified in-place without using any extra
data structure.
*/

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        // Number of rows
        int r = grid.size();

        // Number of columns
        int c = grid[0].size();

        // Stores the increments required for the current cell
        int cnt = 0;

        // Stores the total number of operations
        int ans = 0;

        // Traverse every column
        for (int i = 0; i < c; i++) {

            // Traverse every adjacent pair in the current column
            for (int j = 0; j < r - 1; j++) {

                // Current column is already strictly increasing
                if (grid[j][i] < grid[j + 1][i])
                    continue;

                else {

                    // Calculate the increments required to make
                    // the lower element greater than the upper element
                    cnt += grid[j][i] - grid[j + 1][i] + 1;

                    // Add the operations to the final answer
                    ans += cnt;

                    // Update the value after incrementing
                    grid[j + 1][i] += cnt;

                    // Reset for the next comparison
                    cnt = 0;
                }
            }
        }

        return ans;
    }
};
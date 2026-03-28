#include <iostream>
#include <vector>
using namespace std;

/*
You are given an m x n matrix board containing letters 'X' and 'O', capture 
regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the 
region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within 
the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

*/
// Depth-First Search function to mark connected 'O's
void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &visited) {
    visited[row][col] = 1;
    int n = board.size();
    int m = board[0].size();
    
    // Define possible movement directions (up, down, left, right)
    int drow[] = {1, 0, -1, 0};
    int dcol[] = {0, 1, 0, -1};
    
    // Traverse all four directions
    for (int i = 0; i < 4; i++) {
        int r = row + drow[i];
        int c = col + dcol[i];
        
        // Check if the next cell is within bounds and is an unvisited 'O'
        if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !visited[r][c]) {
            dfs(r, c, board, visited);
        }
    }
}

// Function to solve the problem
void solve(vector<vector<char>> &board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    // Step 1: Mark all boundary-connected 'O's using DFS
    for (int j = 0; j < m; j++) {
        // Check top boundary
        if (!visited[0][j] && board[0][j] == 'O') {
            dfs(0, j, board, visited);
        }
        // Check bottom boundary
        if (!visited[n - 1][j] && board[n - 1][j] == 'O') {
            dfs(n - 1, j, board, visited);
        }
    }
    for (int i = 0; i < n; i++) {
        // Check left boundary
        if (!visited[i][0] && board[i][0] == 'O') {
            dfs(i, 0, board, visited);
        }
        // Check right boundary
        if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
            dfs(i, m - 1, board, visited);
        }
    }
    
    // Step 2: Flip all unvisited 'O's to 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell is 'O' and not visited, change it to 'X'
            if (board[i][j] == 'O' && !visited[i][j]) {
                board[i][j] = 'X';
            }
        }
    }
    
    // Time Complexity: O(N*M) (Each cell is visited at most once)
    // Space Complexity: O(N*M) (Visited array and recursion stack in worst case)
}

// Main function to take input and print output
int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    
    cout << "Enter the board (O/X format):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(board);
    
    cout << "Updated board:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
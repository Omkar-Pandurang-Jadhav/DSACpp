#include <bits/stdc++.h>
using namespace std;

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /* Time Complexity: O(N*M) as each cell is processed once in BFS
           Space Complexity: O(N*M) for queue and visited matrix */
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int cnt = 0;
        
        // Initialize queue with rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                if (grid[i][j] == 1) cnt++;
            }
        }
        
        int tm = 0, cntFresh = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(tm, t);
            
            for (int i = 0; i < 4; i++) {
                int row = r + drow[i];
                int col = c + dcol[i];
                
                if (row >= 0 && row < n && col >= 0 && col < m && visited[row][col] == 0 && grid[row][col] == 1) {
                    q.push({{row, col}, t + 1});
                    visited[row][col] = 2;
                    cntFresh++;
                }
            }
        }
        
        return (cnt == cntFresh) ? tm : -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    Solution sol;
    int result = sol.orangesRotting(grid);
    
    if (result == -1) {
        cout << "All oranges cannot rot." << endl;
    } else {
        cout << "The minimum time required for all oranges to rot is " << result << " minutes." << endl;
    }
    
    return 0;
}

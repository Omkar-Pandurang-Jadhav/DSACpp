#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

/*
    Time Complexity: O(n * m * log(n * m))
    Space Complexity: O(n * m)
*/

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> diff(n, vector<int>(m, INT_MAX));
    diff[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});

    int drow[] = {0, -1, 0, 1};
    int dcol[] = {-1, 0, 1, 0};

    while (!pq.empty()) {
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int r = row + drow[i];
            int c = col + dcol[i];

            if (r >= 0 && r < n && c >= 0 && c < m) {
                int newEffort = max(abs(heights[r][c] - heights[row][col]), d);
                if (newEffort < diff[r][c]) {
                    diff[r][c] = newEffort;
                    pq.push({newEffort, {r, c}});
                }
            }
        }
    }

    return diff[n - 1][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> heights[i][j];
        }
    }

    cout << minimumEffortPath(heights) << endl;
    return 0;
}

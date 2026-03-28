#include <bits/stdc++.h>
using namespace std;

/*
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected
 directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities 
and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0
 otherwise.

Return the total number of provinces.

 */
void dfs(vector<int> adj[], int start, vector<int> &visited) {
    visited[start] = 1;
    for (int i = 0; i < adj[start].size(); i++) {
        if (!visited[adj[start][i]]) {
            dfs(adj, adj[start][i], visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> adj[n];

    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
            }
        }
    }

    int count = 0;
    vector<int> visited(n, 0);

    // Count number of connected components
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(adj, i, visited);
            count++;
        }
    }
    
    return count;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    vector<vector<int>> isConnected(n, vector<int>(n));
    
    cout << "Enter the adjacency matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    int provinces = findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}

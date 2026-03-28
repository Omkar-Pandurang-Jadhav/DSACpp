#include <bits/stdc++.h>
using namespace std;

bool detect(vector<vector<int>> &adj, int src, vector<int> &visited) {
    visited[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (int i = 0; i < adj[node].size(); i++) {
            if (visited[adj[node][i]] == 0) {
                q.push({adj[node][i], node});
                visited[adj[node][i]] = 1;
            } else if (parent != adj[node][i]) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    // Time Complexity: O(V + 2E) where V is the number of vertices and E is the number of edges.
    // Space Complexity: O(V) for the visited array and queue storage.
    int n = adj.size();
    vector<bool> ans;
    vector<int> visited(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            ans.push_back(detect(adj, i, visited));
        }
    }
    
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == true) {
            return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> adj(V);
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (isCycle(adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";
    
    return 0;
}

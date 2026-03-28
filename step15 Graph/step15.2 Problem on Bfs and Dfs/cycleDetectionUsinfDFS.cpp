#include <bits/stdc++.h>
using namespace std;

bool detect(vector<vector<int>> &adj, int src, int parent, vector<int> &visited) {
    visited[src] = 1;
    for (int i = 0; i < adj[src].size(); i++) {
        if (!visited[adj[src][i]]) {
            if (detect(adj, adj[src][i], src, visited)) return true;
        } else if (parent != adj[src][i]) {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    // Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
    // Space Complexity: O(V) for the visited array.
    int n = adj.size();
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (detect(adj, i, -1, visited)) {
                return true;
            }
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

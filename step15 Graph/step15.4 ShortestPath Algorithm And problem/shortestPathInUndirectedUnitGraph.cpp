#include <bits/stdc++.h>
using namespace std;


/*
You are given an adjacency list, adj of Undirected Graph having unit
 weight of the edges, find the shortest path from src to all the vertex and if it is
 unreachable to reach any vertex, then return -1 for that vertex.*/
// Function to perform BFS and compute shortest paths
void bfs(vector<int> &distance, vector<vector<int>> &adj, int src) {
    int n = adj.size();
    queue<int> pq;
    pq.push(src);
    distance[src] = 0;

    while (!pq.empty()) {
        int node = pq.front();
        pq.pop();
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (distance[node] + 1 < distance[neighbor]) {
                distance[neighbor] = distance[node] + 1;
                pq.push(neighbor);
            }
        }
    }
}

// Function to find the shortest path from source to all other nodes
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> distance(n, INT_MAX);
    bfs(distance, adj, src);
    
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            distance[i] = -1;
        }
    }
    return distance;
}

// Time Complexity: O(V + E) — where V = number of vertices, E = number of edges
// Space Complexity: O(V) — for distance array and queue

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        vector<int> res = shortestPath(adj, src);
        for (int x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n"; // Output separator for multiple test cases
    }
    return 0;
}

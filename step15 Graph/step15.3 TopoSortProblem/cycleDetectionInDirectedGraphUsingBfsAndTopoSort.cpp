//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
    Intuition:
    - This algorithm detects a **cycle in a directed graph** using **Kahn's Algorithm (BFS approach)**.
    - We calculate the **in-degree** of each node and use a queue to process nodes with in-degree 0.
    - If we cannot visit all nodes (i.e., topological sorting fails), a cycle exists.
*/

bool isCyclic(vector<vector<int>> &adj, int N) {
    vector<int> indegree(N, 0);
    queue<int> q;
    
    // Compute in-degree of all nodes
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }
    
    // Push nodes with in-degree 0 into the queue
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    if (q.empty()) return true; // If no node has in-degree 0, cycle exists
    
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for (int j = 0; j < adj[node].size(); j++) {
            indegree[adj[node][j]]--;
            if (indegree[adj[node][j]] == 0) {
                q.push(adj[node][j]);
            }
        }
    }
    
    return topo.size() != N; // If topological sort fails, cycle exists
}

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, E;
        cin >> N >> E;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << isCyclic(adj, N) << "\n";
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends

/*
    Time Complexity: O(V + E)
    - Each node is visited once -> O(V)
    - Each edge is processed once -> O(E)
    - Overall: O(V + E)

    Space Complexity: O(V + E)
    - Adjacency list stores E edges -> O(E)
    - In-degree array stores V nodes -> O(V)
    - Queue stores V nodes in worst case -> O(V)
    - Overall: O(V + E)
*/

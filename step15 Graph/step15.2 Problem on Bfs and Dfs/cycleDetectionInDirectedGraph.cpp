#include <bits/stdc++.h>
using namespace std;

/*
    Intuition:
    - This algorithm detects a **cycle in a directed graph** using **DFS and recursion stack tracking**.
    - We use a **visited array** to track visited nodes and a **pathvisited array** to track nodes in the current recursion path.
    - If we revisit a node that is still in the recursion path, a cycle exists.
    - After finishing a path, we mark the node as unvisited in the recursion path.
*/

bool dfs(vector<vector<int>> &adj, int node, vector<int> &visited, vector<int> &pathvisited) {
    visited[node] = 1;
    pathvisited[node] = 1;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(adj, neighbor, visited, pathvisited)) return true;
        } else if (pathvisited[neighbor]) {
            return true;
        }
    }
    
    pathvisited[node] = 0;
    return false;
}

bool isCyclic(int N, vector<vector<int>> &adj) {
    vector<int> visited(N, 0);
    vector<int> pathvisited(N, 0);
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (dfs(adj, i, visited, pathvisited)) return true;
        }
    }
    
    return false;
}

int main() {
    int N, E;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> E;
    
    vector<vector<int>> adj(N);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    cout << (isCyclic(N, adj) ? "Graph contains a cycle" : "Graph does not contain a cycle") << endl;
    
    return 0;
}

/*
    Time Complexity: O(V + E)
    - Each node is visited once -> O(V)
    - Each edge is processed once -> O(E)
    - Overall: O(V + E)

    Space Complexity: O(V + E)
    - Adjacency list stores E edges -> O(E)
    - Visited and PathVisited arrays store V nodes -> O(V)
    - Recursion stack (worst case) -> O(V)
    - Overall: O(V + E)
*/

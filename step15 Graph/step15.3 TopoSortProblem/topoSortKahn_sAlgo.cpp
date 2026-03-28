#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

*/
/*
    Intuition:
    - This algorithm performs **Topological Sorting** using **Kahn's Algorithm (BFS approach)**.
    - It uses an **indegree array** to track the number of incoming edges for each node.
    - Nodes with **zero indegree** are added to the queue and processed first.
    - As we process each node, we reduce the indegree of its neighbors.
    - If a neighbor's indegree becomes zero, it is added to the queue.
    - The final order of processing gives the **topological sorting**.
*/

vector<int> topologicalSort(int N, vector<vector<int>> &adj) {
    vector<int> indegree(N, 0);
    queue<int> q;
    
    // Calculate indegree for each node
    for (int i = 0; i < N; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    
    // Push nodes with zero indegree into the queue
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return ans;
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
    
    vector<int> res = topologicalSort(N, adj);
    
    cout << "Topological Sort Order: ";
    for (int node : res) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

/*
    Time Complexity: O(V + E)
    - Each node is processed once -> O(V)
    - Each edge is processed once -> O(E)
    - Overall: O(V + E)

    Space Complexity: O(V + E)
    - Adjacency list stores E edges -> O(E)
    - Indegree array stores V nodes -> O(V)
    - Queue stores up to V nodes -> O(V)
    - Overall: O(V + E)
*/

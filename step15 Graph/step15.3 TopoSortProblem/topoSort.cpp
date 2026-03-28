#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

*/
/*
    Intuition:
    - This algorithm performs **Topological Sorting** using **DFS and Stack**.
    - Topological sorting is only possible for **Directed Acyclic Graphs (DAGs)**.
    - We use DFS to visit all nodes and push them onto a stack **after all its neighbors are processed**.
    - Finally, we pop elements from the stack to get the topological ordering.
*/

void dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, st, adj);
        }
    }   
    st.push( node);
}

vector<int> topologicalSort(int N, vector<vector<int>> &adj) {
    vector<int> visited(N, 0);
    stack<int> st;
    
    for (int i = 0; i < N; i++) { 
        if (!visited[i]) {
            dfs(i, visited, st, adj);
        }
    }
    
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
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
    - Each node is visited once -> O(V)
    - Each edge is processed once -> O(E)
    - Overall: O(V + E)

    Space Complexity: O(V + E)
    - Adjacency list stores E edges -> O(E)
    - Visited array stores V nodes -> O(V)
    - Recursion stack (worst case) -> O(V)
    - Explicit stack stores V nodes -> O(V)
    - Overall: O(V + E)
*/

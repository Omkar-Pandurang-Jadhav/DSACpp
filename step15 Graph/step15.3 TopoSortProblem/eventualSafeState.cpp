/* There is a directed graph of n nodes with each node labeled from 0
 to n - 1. The graph is represented by a 0-indexed 2D integer array graph
  where graph[i] is an integer array of nodes adjacent to node i, meaning 
  there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A 
node is a safe node if every possible path starting from that node 
leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph.
 The answer should be sorted in ascending order.*/
#include <bits/stdc++.h>
using namespace std;

/*
    Intuition:
    - A node is **safe** if all paths from it lead to a terminal node.
    - Instead of processing from the source, we **reverse the graph** and process from terminal nodes.
    - This is done using **Kahn’s algorithm (Topological Sort - BFS)**:
      1. Reverse the edges.
      2. Compute in-degrees.
      3. Process nodes with in-degree 0.
    - The remaining nodes in the order are safe nodes.
*/

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> adjRev(n);
    vector<int> indegree(n, 0);

    // Reverse the graph and compute in-degrees
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            adjRev[graph[i][j]].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> safeNode;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safeNode.push_back(node);

        for (int i = 0; i < adjRev[node].size(); i++) {
            indegree[adjRev[node][i]]--;
            if (indegree[adjRev[node][i]] == 0) q.push(adjRev[node][i]);
        }
    }

    sort(safeNode.begin(), safeNode.end());
    return safeNode;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<vector<int>> graph(n);

    cout << "Enter adjacency list (terminate each list with -1):\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> ";
        int neighbor;
        while (cin >> neighbor && neighbor != -1) {
            graph[i].push_back(neighbor);
        }
    }

    vector<int> result = eventualSafeNodes(graph);
    cout << "Safe nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}

/*
    Time Complexity: O(V + E)
    - Each node is processed once -> O(V)
    - Each edge is processed once -> O(E)
    - Overall: O(V + E)

    Space Complexity: O(V + E)
    - Adjacency list stores E edges -> O(E)
    - In-degree array stores V nodes -> O(V)
    - Queue stores V nodes in worst case -> O(V)
    - Overall: O(V + E)
*/

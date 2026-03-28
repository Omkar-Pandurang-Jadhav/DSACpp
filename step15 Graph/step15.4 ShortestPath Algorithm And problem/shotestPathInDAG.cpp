#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and 
a 2D Integer array(or vector) edges[ ][ ] of length E, where there 
is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is 
impossible to reach any vertex, then return -1 for that vertex.*/
// User function Template for C++
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    vector<int> distance(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    distance[0] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        for (int i = 0; i < adj[node].size(); i++) {
            if (dist + adj[node][i].second < distance[adj[node][i].first]) {
                distance[adj[node][i].first] = dist + adj[node][i].second;
                pq.push({dist + adj[node][i].second, adj[node][i].first});
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX) distance[i] = -1;
    }

    // Time Complexity: O((V + E) * log V)
    // Space Complexity: O(V + E)
    return distance;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        vector<int> res = shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest distance of all the vertices from the source vertex src.
vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> distance(adj.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    distance[src] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (int i = 0; i < adj[node].size(); i++) {
            if (dist + adj[node][i].second < distance[adj[node][i].first]) {
                distance[adj[node][i].first] = dist + adj[node][i].second;
                pq.push({distance[adj[node][i].first], adj[node][i].first});
            }
        }
    }

    // Time Complexity: O((V + E) * log V)
    // Space Complexity: O(V + E)
    return distance;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // Because graph is undirected
        }

        int src;
        cin >> src;
        cin.ignore();

        vector<int> res = dijkstra(adj, src);
        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

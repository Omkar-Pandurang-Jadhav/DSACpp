// User function template for C++

/*
You are given an weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n,
 where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge,
  dist[i][j] is set to a large value (i.e., 108) to represent infinity.
The graph may contain negative edge weights, but it does not contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes i and j in the graph.

Note: Modify the distances for every pair in place.

Examples :*/

/* TC-> O(N^3)*/
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();

        // Run Floyd-Warshall Algorithm
        // Iterate through all possible intermediate vertices k
        for (int k = 0; k < n; k++) {
            // For each pair of vertices (i, j)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // If there is a path from i to k and k to j
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
                        // Update dist[i][j] if a shorter path is found via vertex k
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Detect Negative Weight Cycle
        // If dist[i][i] < 0 for any vertex i, a negative weight cycle exists
        for (int i = 0; i < n; i++) {
            if (dist[i][i] < 0) {
                // You can handle it however you need:
                // e.g., print a message or return a special value
                cout << "Negative weight cycle detected at vertex " << i << endl;
                return;
            }
        }
    }
};

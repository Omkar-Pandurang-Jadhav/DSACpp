

/*
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][],
 where edges[i] = [u, v, w] represents a direct edge from node u to v 
having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable 
from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle,
 return [-1] to indicate that shortest paths cannot be reliably computed.*/


// User function Template for C++

class Solution {
  public:
    // Function to implement Bellman-Ford algorithm
    // V = number of vertices, edges = list of {u, v, w}, src = source vertex
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        int e = edges.size(); // Number of edges in the graph

        // Initialize distances to all vertices as 1e8 (representing infinity)
        vector<int> dist(V, 1e8);

        // Distance to source vertex is 0
        dist[src] = 0;

        // Perform (V-1) iterations to relax all edges
        for(int i = 0; i < V-1; i++){
            // For each edge, attempt to relax it
            for(int j = 0; j < e; j++){
                int edW = edges[j][2];     // Edge weight
                int adjNode = edges[j][1]; // Destination node
                int par = edges[j][0];     // Source node

                // If 'par' is reachable and a shorter path to 'adjNode' is found
                if(dist[par] != 1e8 && dist[par] + edW < dist[adjNode]){
                    // Update the distance to 'adjNode'
                    dist[adjNode] = dist[par] + edW;
                }
            }
        }

        // Perform one more iteration to check for negative weight cycles
        for(int j = 0; j < e; j++){
            int edW = edges[j][2];     // Edge weight
            int adjNode = edges[j][1]; // Destination node
            int par = edges[j][0];     // Source node

            // If a shorter path is still possible, and 'par' is reachable
            // then a negative weight cycle exists
            if(dist[par] != 1e8 && dist[par] + edW < dist[adjNode]){
                // As per problem statement, return {-1} if negative cycle detected
                return {-1};
            }
        }

        // Return the final shortest distance array
        // Unreachable vertices remain as 1e8
        return dist;
    }
};


/* TC->O(V*E)*/
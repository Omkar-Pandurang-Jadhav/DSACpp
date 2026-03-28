/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti]
 represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is 
at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize adjacency matrix with large values (1e9 representing infinity)
        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        // Step 2: Set distance to self as 0
        for (int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        // Step 3: Fill in the adjacency matrix with given edge weights (since undirected, fill both [u][v] and [v][u])
        int e = edges.size();
        for (int i = 0; i < e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mat[u][v] = w;
            mat[v][u] = w;
        }

        // Step 4: Apply Floyd-Warshall algorithm to compute all-pairs shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] != 1e9 && mat[k][j] != 1e9) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        // Step 5: For each city, count how many other cities are reachable within distanceThreshold
        vector<int> dist(n, 1e9);
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && mat[i][j] <= distanceThreshold) {
                    num++;
                }
            }
            dist[i] = num;  // Store count of reachable cities from city i
        }

        // Step 6: Find the minimum number of reachable cities
        int mini = dist[0];
        for (int i = 1; i < n; i++) {
            if (mini > dist[i]) {
                mini = dist[i];
            }
        }

        // Step 7: Use a max-heap (priority queue without 'greater<int>') to store cities with min reachable count
        // This ensures that city with the largest number gets priority (since max-heap picks largest first)
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (dist[i] == mini) {
                pq.push(i);
            }
        }

        // Step 8: Return the city with the largest number among those with min reachable count
        int ans = pq.top();
        return ans;
    }
};

/*
TC-> O(N^3)
*/
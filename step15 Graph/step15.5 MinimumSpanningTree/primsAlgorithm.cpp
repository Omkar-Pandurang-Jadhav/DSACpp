class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap priority queue: {edgeWeight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Push starting node 0 with edge weight 0
        pq.push({0, 0});

        // Visited array to track nodes included in MST
        vector<int> visited(V, 0);

        // Variable to store total weight of MST
        int sum = 0;

        // Prim's Algorithm loop
        while (!pq.empty()) {
            int wt = pq.top().first;   // Weight of current edge
            int node = pq.top().second; // Node number
            pq.pop();

            // If already visited, skip this node
            if (visited[node] == 1) continue;

            // Mark node as visited
            visited[node] = 1;

            // Add current edge weight to total MST weight
            sum += wt;

            // Traverse all adjacent nodes of current node
            for (auto iter : adj[node]) {
                int adjNode = iter[0]; // Neighbor node
                int edW = iter[1];     // Edge weight

                // If adjacent node not visited, push it into priority queue
                if (!visited[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }

        // Return total weight of MST
        return sum;
    }
};

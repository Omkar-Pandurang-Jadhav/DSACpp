
/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel 
times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, 
and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to 
receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list for the graph where each node has a list of {neighbor, weight}
        vector<vector<pair<int,int>>> adj(n+1);
        
        // Number of edges in the graph (size of the times array)
        int t=times.size();
        
        // Build the adjacency list from the times array
        for(int i=0;i<t;i++){
            // times[i][0] is source, times[i][1] is destination, times[i][2] is travel time
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        // Distance vector initialized with INT_MAX (representing infinity)
        vector<int> dist(n+1,INT_MAX);

        // Min-heap priority queue storing {current_time, node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        // Push the starting node (signal source) into the queue with time 0
        pq.push({0,k});

        // Distance to source node is 0
        dist[k]=0;

        // Process the priority queue until it's empty
        while(!pq.empty()){
            // Get the node with the smallest current time
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            // Traverse all adjacent nodes (neighbors) of the current node
            for(auto iter:adj[node]){
                int adjNode=iter.first;      // neighbor node
                int edW=iter.second;         // edge weight (travel time)

                // If current path to neighbor through this node is shorter, update it
                if(edW+d<dist[adjNode]){
                    dist[adjNode]=edW+d;     // Update distance
                    pq.push({edW+d,adjNode}); // Push updated distance and neighbor into the queue
                }
            }
        }

        // After Dijkstra's, check if all nodes are reachable
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1; // If any node is unreachable, return -1
        }

        // Find the maximum time taken to reach any node (as signal must reach all)
        int max=dist[1];
        for(int i=2;i<=n;i++){
            if(max<dist[i]){
                max=dist[i]; // Keep updating max time
            }
        }

        // Return the total time for the signal to reach all nodes
        return max;
    }
};

/*

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a 
network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer
 can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly 
connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

*/

class Solution {
public:
    // Disjoint Set (Union-Find) data structures
    vector<int> rank;   // To store rank (tree height) of each set
    vector<int> parent; // To store parent of each node in the set

    // Function to initialize parent and rank arrays for n nodes
    void makeArrangement(int n){
        rank.resize(n, 0);       // Initially, rank of all nodes is 0
        parent.resize(n);        // Resize parent array to hold n elements
        for(int i = 0; i < n; i++){
            parent[i] = i;       // Initially, every node is its own parent
        }
    }

    // Function to find ultimate parent of a node (with path compression)
    int findUPar(int node){
        if(node == parent[node]){    // If node is its own parent
            return node;
        }
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    // Function to perform union of two sets by their rank
    void unionByRank(int a, int b){
        int ua = findUPar(a);   // Find ultimate parent of a
        int ub = findUPar(b);   // Find ultimate parent of b

        if(ua == ub) return;    // If already in the same set, do nothing

        // Attach smaller rank tree under larger rank tree
        if(rank[ua] < rank[ub]){
            parent[ua] = ub;
        }
        else if(rank[ua] > rank[ub]){
            parent[ub] = ua;
        }
        else {
            parent[ub] = ua;    // If ranks equal, attach one to another and increase rank
            rank[ua]++;
        }
    }

    // Main function to compute minimum operations to connect the network
    int makeConnected(int n, vector<vector<int>>& connections) {
        makeArrangement(n);  // Initialize Disjoint Set for n computers

        int cE = 0;  // Count of extra cables (edges) which connect already connected components

        // Iterate over all existing connections
        for(int i = 0; i < connections.size(); i++){
            // If computers are in different components, connect them
            if(findUPar(connections[i][0]) != findUPar(connections[i][1])){
                unionByRank(connections[i][0], connections[i][1]);
            }
            else {
                cE++;  // If already connected, this is an extra cable
            }
        }

        int components = 0; // Number of connected components in the network

        // Count number of connected components by counting ultimate parents
        for(int i = 0; i < n; i++){
            if(i == findUPar(i)) components++;
        }

        int ans = components - 1; // Minimum cables needed to connect all components

        // If extra cables are sufficient, return answer, else return -1
        if(cE >= ans) return ans;
        return -1;
    }
};

// Include necessary header files
#include<bits/stdc++.h>
using namespace std;


/* 
TC-> O(ELogE)+O(E*Alpha)
*/
// Solution class containing Disjoint Set and Kruskal's implementation
class Solution {
  public:
    // Vectors to store parent of each node and their rank (tree height)
    vector<int> parent;
    vector<int> treerank;

    // Function to initialize Disjoint Set
    void DisjointSet(int n) {
        treerank.resize(n + 1, 0);  // Initially, rank of all nodes is 0
        parent.resize(n + 1);       // Resize parent array to size n+1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;          // Every node is initially its own parent
        }
    }

    // Function to find ultimate parent of node x (with path compression)
    int findUPar(int x) {
        if (x == parent[x]) return x;                 // If node is its own parent, return it
        return parent[x] = findUPar(parent[x]);       // Else, recursively find and compress path
    }

    // Comparator function to sort edges according to their weight (static because sort needs it)
    static bool sortAccordingToWeight(vector<int>& e1, vector<int>& e2) {
        return e1[2] < e2[2];     // Compare weights at index 2 of edge vectors
    }

    // Function to perform union by rank
    int unionByRank(int x, int y) {
        int px = findUPar(x);     // Find ultimate parent of x
        int py = findUPar(y);     // Find ultimate parent of y

        if (px == py) return 0;   // If both have same parent, they're already connected

        // Attach smaller tree under larger tree (union by rank)
        if (treerank[px] > treerank[py]) {
            parent[py] = px;      // Attach y's tree under x's tree
        }
        else if (treerank[px] < treerank[py]) {
            parent[px] = py;      // Attach x's tree under y's tree
        }
        else {
            parent[py] = px;      // If equal rank, attach y under x and increase x's rank
            treerank[px]++;
        }
        return 1;                 // Return 1 to indicate union was performed
    }

    // Kruskal's MST implementation
    int kruskalsMST(int V, vector<vector<int>>& edges) {
        int sum = 0;     // Variable to store total weight of MST

        // Sort all edges in increasing order of weight using static comparator
        sort(edges.begin(), edges.end(), Solution::sortAccordingToWeight);

        int e = edges.size();   // Total number of edges in the graph
        DisjointSet(V);         // Initialize Disjoint Set for V vertices

        // Iterate over all sorted edges
        for (int i = 0; i < e; i++) {
            int u = edges[i][0];   // Node u
            int v = edges[i][1];   // Node v
            int w = edges[i][2];   // Edge weight

            // If including this edge doesn’t cause a cycle
            if (unionByRank(u, v)) {
                sum += w;   // Add edge weight to MST total weight
            }
        }

        return sum;  // Return total weight of MST
    }
};

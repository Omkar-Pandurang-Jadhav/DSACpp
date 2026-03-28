/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, 
return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
*/

// Leetcode: Remove Most Stones with Union-Find (Disjoint Set Union - DSU)
// Time Complexity: O(N * α(N))   where α(N) is the inverse Ackermann function (nearly constant)
// Space Complexity: O(R + C)     where R is the maximum row number and C is the maximum column number used

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;      // parent[i] represents the parent (leader) of the node i
    vector<int> treerank;    // treerank[i] represents the rank (height) of the tree rooted at i

    // Function to initialize DSU with n nodes
    void DisjointSet(int n) {
        treerank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Initially every node is its own parent
        }
    }

    // Path Compression: Recursively finds ultimate parent and compresses the path
    int findUPar(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findUPar(parent[x]);
    }

    // Union by Rank: Attaches the tree with lower rank under the tree with higher rank
    void unionByRank(int x, int y) {
        int px = findUPar(x);
        int py = findUPar(y);
        if (px == py) return; // Already in the same component

        if (treerank[px] > treerank[py]) {
            parent[py] = px;
        }
        else if (treerank[px] < treerank[py]) {
            parent[px] = py;
        }
        else {
            parent[py] = px;
            treerank[px]++;
        }
    }

    // Main function to remove stones
    int removeStones(vector<vector<int>>& stones) {
        int s = stones.size();
        int maxRow = 0, maxCol = 0;

        // Find max row and column numbers to size the DSU array properly
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Initialize DSU of size (maxRow + maxCol + 2)
        DisjointSet(maxRow + maxCol + 2);

        set<int> st; // To keep track of all unique indices (rows and columns used)

        // For each stone, union its row and column index (offset column index to avoid overlap)
        for (int i = 0; i < s; i++) {
            int rowNode = stones[i][0];
            int colNode = maxRow + 1 + stones[i][1];
            unionByRank(rowNode, colNode);

            // Mark both row and col node as active (used)
            st.insert(rowNode);
            st.insert(colNode);
        }

        // Count the number of connected components (ultimate parents) among the used indices
        int cnt = 0;
        for (auto it : st) {
            if (findUPar(it) == it) cnt++;
        }

        // Maximum stones removable = total stones - number of components
        int ans = s - cnt;
        return ans;
    }
};

/*
Approach:
-----------
- Treat each row and column as a separate node in a Disjoint Set.
- Connect the row and corresponding column node for each stone.
- Finally, count how many connected components exist among the involved nodes.
- The answer is (number of stones - number of components).
  Because in each connected component of size K, you can remove K-1 stones.

Time Complexity:
----------------
O(N * α(N))  where α(N) is inverse Ackermann function, nearly constant for practical input sizes.

Space Complexity:
-----------------
O(R + C) for parent, treerank arrays and set storing active nodes.
*/

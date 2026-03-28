/*

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
*/

// Problem: You are given an n x n binary matrix grid. You can change at most one '0' to '1'.
// Return the size of the largest island (4-directionally connected group of 1's) after this operation.

// Approach:
// 1️⃣ Use Disjoint Set Union (DSU) to group together connected 1’s as islands.
// 2️⃣ For each 0 in the grid, check its 4 neighbors — collect the unique island components around it.
// 3️⃣ Sum up the sizes of these unique connected components (using DSU) and see what would be the new island size if this 0 was flipped.
// 4️⃣ Track the maximum such possible island size.
// 5️⃣ If grid is already full of 1’s, handle that as an edge case separately.

class Solution {
public:
    vector<int> parent;   // DSU parent array
    vector<int> treerank; // DSU rank array (for union by rank)
    vector<int> size;     // DSU size array (for union by size)

    // Function to initialize Disjoint Set Union structure for n elements
    void DisjointSet(int n) {
        treerank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Each node is initially its own parent
            size[i] = 1;    // Initial size of each component is 1
        }
    }

    // Find ultimate parent with path compression
    int findUPar(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findUPar(parent[x]);
    }

    // Union two components by size
    void unionBySize(int x, int y) {
        int px = findUPar(x);
        int py = findUPar(y);

        if (px == py) return; // Already in same set

        // Attach smaller component under larger component
        if (size[px] > size[py]) {
            parent[py] = px;
            size[px] += size[py];
        }
        else {
            parent[px] = py;
            size[py] += size[px];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();  // Size of the grid
        DisjointSet(n * n);   // Initialize DSU for n * n elements (each cell treated as node)

        // Arrays for 4-directional movement
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Step 1: Connect all adjacent 1's in the grid using DSU
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        // If neighbor is within bounds and also 1
                        if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c]) {
                            // Connect current cell with its neighbor using DSU
                            unionBySize(i * n + j, r * n + c);
                        }
                    }
                }
            }
        }

        int cnt = 0;  // Variable to track maximum island size after flipping a 0

        // Step 2: For each 0 cell, check its 4 neighboring components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;  // To store unique component parents
                    int temp = 0;

                    for (int k = 0; k < 4; k++) {
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c]) {
                            st.insert(findUPar(r * n + c));  // Insert unique parent
                        }
                    }

                    // Sum up sizes of all unique neighboring components
                    for (auto it : st) {
                        temp += size[it];
                    }

                    // Update max island size after flipping this 0
                    cnt = max(cnt, temp);
                }
            }
        }

        // Step 3: Handle edge case when no 0 is present (fully filled grid)
        if (cnt == 0) {
            if (grid[0][0] == 0) return 1;  // If grid is all 0's, flipping one makes size 1
            return n * n;  // If grid is all 1's, largest island is entire grid
        }

        return cnt + 1;  // Add 1 for the flipped 0 cell
    }
};

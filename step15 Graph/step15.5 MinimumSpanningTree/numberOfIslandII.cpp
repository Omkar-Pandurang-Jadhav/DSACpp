/*

You are given a n,m which means the row and column of the 2D matrix and an array of 
 size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if 
 there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. 
 The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change 
 the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after 
 each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

 

Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
    */

    // User function Template for C++
class Solution {
  public:

  // Disjoint Set Union (DSU) data structures: parent and rank arrays
  vector<int> parent;
  vector<int> treerank;

  // Function to initialize DSU with 'n' nodes
  void DisjointSet(int n) {
        treerank.resize(n + 1, 0);   // Initialize rank array with 0
        parent.resize(n + 1);        // Initialize parent array
        for (int i = 0; i <= n; i++) {
            parent[i] = i;           // Initially, each node is its own parent
        }
    }

  // Function to find the ultimate parent of node 'x' with path compression
  int findUPar(int x){
      if(x == parent[x]) return x;               // If node is its own parent, return it
      return parent[x] = findUPar(parent[x]);    // Path compression optimization
  }

  // Function to perform union of two sets by rank
  void unionByRank(int x, int y){
      int px = findUPar(x);  // Find parent of x
      int py = findUPar(y);  // Find parent of y

      if(px == py) return ;  // Already in the same set, no need to merge

      // Merge the smaller rank tree under the bigger one
      if(treerank[px] > treerank[py]){
          parent[py] = px;
      }
      else if(treerank[px] < treerank[py]){
          parent[px] = py;
      }
      else{
          parent[py] = px;
          treerank[px]++;   // Increase rank when both have same rank
      }
  }

  // Main function to compute number of islands after each operator
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
      DisjointSet(m*n);  // Initialize DSU for n*m cells (flattened)

      int k = operators.size();                    // Number of operations
      vector<vector<int>> mat(n, vector<int>(m, 0)); // 2D grid initialized with water (0)
      vector<int> ans(k);                          // To store number of islands after each operation
      int cnt = 0;                                  // Current number of islands

      // Arrays for 4-directional movement (top, right, bottom, left)
      int drow[] = {-1, 0, 1, 0};
      int dcol[] = {0, 1, 0, -1};

      // Iterate over each operator
      for(int i = 0; i < k; i++){
          int row = operators[i][0];   // Get row index of operation
          int col = operators[i][1];   // Get col index of operation

          // If the cell is already land, skip it
          if(!mat[row][col]){
              mat[row][col] = 1;   // Mark cell as land
              cnt++;               // New island formed (for now)

              // Check all 4 neighboring cells
              for(int j = 0; j < 4; j++){
                  int r = row + drow[j];  // Neighbor row
                  int c = col + dcol[j];  // Neighbor col

                  // If neighbor is valid and land
                  if(r >= 0 && r < n && c >= 0 && c < m && mat[r][c]){
                      // If their parents are different, merge them
                      if(findUPar(m*row+col) != findUPar(m*r+c)){
                          unionByRank(m*row+col, m*r+c);  // Union current cell and neighbor
                          cnt--;  // Merging two islands decreases island count
                      }
                  }
              }
          }
          ans[i] = cnt;  // Store current island count
      }
      return ans;  // Return answer vector
  }
};

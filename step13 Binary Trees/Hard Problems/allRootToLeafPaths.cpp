/*
Given a Binary Tree, you need to find all the possible paths from the root node to all
 the leaf nodes of the binary tree.

Note: The paths should be returned such that paths from the left subtree of any node 
are listed first, followed by paths from the right subtree.

Examples:

Input: root[] = [1, 2, 3, 4, 5, N, N]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]]
Explanation: All the possible paths from root node to leaf nodes are:
 1 -> 2 -> 4, 1 -> 2 -> 5 and 1 -> 3
 */

 /*
============================================================
ALL ROOT TO LEAF PATHS IN BINARY TREE (DFS + BACKTRACKING)
============================================================

APPROACH:
- Use DFS traversal with a temporary vector (temp)
- For each node:
    → Add node value to temp
    → If it is a leaf node:
        → Push temp into answer
    → Recur for left and right child
    → Backtrack (remove last element from temp)

- Backtracking ensures correct path formation

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited once
→ Copying path at leaf nodes contributes overall O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(h)

→ Recursion stack
→ h = height of tree
→ Worst case: O(n)
→ Best case: O(log n)

============================================================
*/

class Solution {
  public:
   void rootToLeafPaths(Node *root,vector<vector<int>> &ans,vector<int> &temp){
       if(!root) return;

       temp.push_back(root->data);

       if(root->left) rootToLeafPaths(root->left,ans,temp);
       if(root->right) rootToLeafPaths(root->right,ans,temp);

       if(!root->left && !root->right)
           ans.push_back(temp);

       temp.pop_back();
   }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;

        rootToLeafPaths(root,ans,temp);

        return ans;
    }
};
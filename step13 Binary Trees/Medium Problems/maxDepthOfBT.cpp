/*
============================================================
MAXIMUM DEPTH (HEIGHT) OF BINARY TREE
============================================================

APPROACH:
- Use recursion (DFS)
- For each node:
    → Compute height of left subtree
    → Compute height of right subtree
    → Take max of both and add 1 (for current node)
- Base case:
    → If node is NULL → return 0

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited exactly once

------------------------------------------------------------

SPACE COMPLEXITY:
O(h)

→ Recursion stack space
→ h = height of tree
→ Worst case (skewed tree): O(n)
→ Best case (balanced tree): O(log n)

============================================================
*/

class Solution {
public:
    int height(TreeNode *root){
        if(root==NULL) return 0;

        return 1+max(height(root->left),height(root->right));
    }
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};


/*

Easy
Topics
premium lock icon
Companies
Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the difference in height between the 
left and right subtrees of any node is no more than one.
============================================================
CHECK BALANCED BINARY TREE (OPTIMIZED)
============================================================

APPROACH:
- Use DFS
- For each node:
    → Get height of left subtree
    → Get height of right subtree
    → If any subtree is unbalanced → return -1
    → If height difference > 1 → return -1
    → Else return height

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node visited once

------------------------------------------------------------

SPACE COMPLEXITY:
O(h)

→ Recursion stack

============================================================
*/

class Solution {
public:
    int check(TreeNode* root){
        if(root == NULL) return 0;

        int left = check(root->left);
        if(left == -1) return -1;

        int right = check(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
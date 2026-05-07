/*
Given the root of a binary tree, check whether it is a mirror of itself 
(i.e., symmetric around its center).

Input: root = [1,2,2,3,4,4,3]
Output: true
*/


/*
============================================================
CHECK SYMMETRIC BINARY TREE (MIRROR CHECK - DFS)
============================================================

APPROACH:
- A tree is symmetric if left subtree is mirror of right subtree
- Use recursion to compare two nodes (l, r):
    → If both are NULL → symmetric
    → If one is NULL → not symmetric
    → If values differ → not symmetric
    → Recursively check:
        l->left  with r->right
        l->right with r->left

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited once

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
    bool check(TreeNode* l,TreeNode* r){
        if(!l && !r) return true;
        if(!l) return false;
        if(!r) return false;

        bool lft=check(l->left,r->right);
        bool rht=check(l->right,r->left);

        if(l->val!=r->val) return false;

        return lft & rht;   // works but && is better
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right);
    }
};
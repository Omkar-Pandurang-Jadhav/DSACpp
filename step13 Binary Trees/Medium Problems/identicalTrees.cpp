/*
Given the roots of two binary trees p and q, write a function to check if 
they are the same or not.

Two binary trees are considered the same if they are structurally identical,
 and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true*/

/*
============================================================
CHECK IF TWO BINARY TREES ARE IDENTICAL
============================================================

APPROACH:
- Use recursion (DFS)
- For each pair of nodes (p, q):
    → If both are NULL → return true
    → If one is NULL → return false
    → If values differ → return false
    → Recursively check left subtrees
    → Recursively check right subtrees
- Return true only if both left and right match

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited once
→ n = number of nodes (assuming both trees have similar size)

------------------------------------------------------------

SPACE COMPLEXITY:
O(h)

→ Recursion stack space
→ h = height of tree
→ Worst case (skewed): O(n)
→ Best case (balanced): O(log n)

============================================================
*/

class Solution {
public:
    bool check(TreeNode *p ,TreeNode *q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL) return false;
        if(q==NULL) return false;
        if(p->val!=q->val) return false;

        bool left=check(p->left,q->left);
        bool right=check(p->right,q->right);

        return left & right;   // works but better to use &&
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};
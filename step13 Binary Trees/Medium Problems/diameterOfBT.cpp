/*
The diameter of a binary tree is the length of the longest path between 
any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges 
between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].*/


/*
============================================================
DIAMETER OF BINARY TREE (OPTIMIZED DFS)
============================================================

APPROACH:
- Use DFS to compute height of each subtree
- For every node:
    → Compute left subtree height
    → Compute right subtree height
    → Update diameter as (left + right)
- Return height to parent (1 + max(left, right))
- Maintain diameter by reference to avoid recomputation

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited exactly once

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
    int check(TreeNode* root,int &diameter){
        if(root==NULL) return 0;

        int left=check(root->left,diameter);
        int right=check(root->right,diameter);

        if(diameter < left + right) diameter = left + right;

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = -1;
        check(root,diameter);
        return diameter;
    }
};
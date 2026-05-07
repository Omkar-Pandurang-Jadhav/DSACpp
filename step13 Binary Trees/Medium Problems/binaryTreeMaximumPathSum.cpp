/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in
 the sequence has an edge connecting them. A node can only appear in the sequence at 
 most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/

/*
============================================================
MAXIMUM PATH SUM IN BINARY TREE
============================================================

APPROACH:
- Use DFS (postorder traversal)
- For each node:
    → Compute maximum path sum from left subtree
    → Compute maximum path sum from right subtree
    → Ignore negative contributions using max(0, …)
    → Update global maximum using:
        left + right + root->val (path passing through root)
- Return the maximum path sum extending upward:
    → root->val + max(left, right)

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
    int check(TreeNode* root,int &pathSum){
        if(root==NULL) return 0;

        int left=check(root->left,pathSum);
        int right=check(root->right,pathSum);

        left = max(0, left);
        right = max(0, right);

        if(pathSum < left + right + root->val)
            pathSum = left + right + root->val;

        return max(root->val, max(left + root->val, right + root->val));
    }

    int maxPathSum(TreeNode* root) {
        int pathSum = root->val;
        check(root,pathSum);
        return pathSum;
    }
};  
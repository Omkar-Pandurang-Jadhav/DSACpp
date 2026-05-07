/*
============================================================
INORDER TRAVERSAL OF BINARY TREE (RECURSIVE)
============================================================

APPROACH:
- Use recursion (DFS)
- Follow inorder sequence:
    → Traverse left subtree
    → Visit root
    → Traverse right subtree
- Store values in vector during traversal

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
    void inOT(TreeNode *root,vector<int> & ans){
        if(root==NULL) return ;
        inOT(root->left,ans);
        ans.push_back(root->val);
        inOT(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOT(root,ans);
        return ans;
    }
};
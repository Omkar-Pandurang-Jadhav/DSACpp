/*
============================================================
PREORDER TRAVERSAL OF BINARY TREE (RECURSIVE)
============================================================

APPROACH:
- Use recursion (DFS)
- Follow preorder sequence:
    → Visit root
    → Traverse left subtree
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
    void preOT(TreeNode *root,vector<int> & ans){
        if(root==NULL) return ;
        ans.push_back(root->val);
        preOT(root->left,ans);
        preOT(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preOT(root,ans);
        return ans;
    }
};
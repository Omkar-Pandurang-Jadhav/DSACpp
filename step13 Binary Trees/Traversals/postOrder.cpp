/*
============================================================
POSTORDER TRAVERSAL OF BINARY TREE (RECURSIVE)
============================================================

APPROACH:
- Use recursion (DFS)
- Follow postorder sequence:
    → Traverse left subtree
    → Traverse right subtree
    → Visit root
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
    void postOT(TreeNode *root,vector<int> & ans){
        if(root==NULL) return ;
        postOT(root->left,ans);
        postOT(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOT(root,ans);
        return ans;
    }
};
/*
Given the root of a binary tree, return the level order traversal of its nodes' values.
 (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]*/

/*
============================================================
LEVEL ORDER TRAVERSAL OF BINARY TREE (BFS)
============================================================

APPROACH:
- Use queue storing (node, level)
- Start with root at level 0
- For each node:
    → If level not present in ans → create new vector
    → Add node value to corresponding level
    → Push left and right children with level+1
- Continue until queue is empty

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited exactly once

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Queue stores nodes (worst case: one full level)
→ Answer vector stores all nodes

============================================================
*/

class Solution {
public:
    void bfs(TreeNode* root,vector<vector<int>> & ans){
        if(root==NULL) return;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode *top=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level==ans.size()) ans.push_back({});

            ans[level].push_back(top->val);
            if(top->left!=NULL) q.push({top->left,level+1});
            if(top->right!=NULL) q.push({top->right,level+1});
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root,ans);
        return ans;
    }
};
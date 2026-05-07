/*
Given the root of a binary tree, return the zigzag level order traversal 
of its nodes' values. (i.e., from left to right, then right to left for the next level 
and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]*/

/*
============================================================
ZIGZAG LEVEL ORDER TRAVERSAL (USING DEQUE + BFS)
============================================================

APPROACH:
- Use BFS with queue storing (node, level)
- Maintain a vector of deque for levels
- For each node:
    → If level is new → create deque
    → If level is odd → insert at front
    → If level is even → insert at back
- After BFS, convert each deque into vector
- Return final 2D vector

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ BFS traversal: O(n)
→ Conversion (deque → vector): O(n)
→ Total: O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Queue stores nodes: O(n)
→ temp (deque storage): O(n)
→ ans (final result): O(n)

============================================================
*/

class Solution {
public:
    void bfs(TreeNode* root,vector<deque<int>> & ans){
        if(root==NULL) return;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode *top=q.front().first;
            int level=q.front().second;
            q.pop();

            if(level==ans.size()) ans.push_back({});

            if(level%2==1) ans[level].push_front(top->val);
            else ans[level].push_back(top->val);

            if(top->left!=NULL) q.push({top->left,level+1});
            if(top->right!=NULL) q.push({top->right,level+1});
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<deque<int>> temp;
        vector<vector<int>> ans;

        bfs(root,temp);

        for(int i=0;i<temp.size();i++){
            ans.push_back(vector<int>(temp[i].begin(),temp[i].end()));
        }

        return ans;
    }
};
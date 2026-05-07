/*
============================================================
RIGHT VIEW OF BINARY TREE (BFS + MAP)
============================================================

APPROACH:
- Use BFS traversal with queue storing:
    → node + level

- Maintain map<int, vector<int>>:
    → key = level
    → value = nodes in BFS order at that level

- For each node:
    → Insert node->data into mpp[level]
    → Push left child first, then right child

- Since BFS processes left → right:
    → Last node at each level = right view

- Finally:
    → Traverse map in level order
    → Take last element of each level

------------------------------------------------------------

TIME COMPLEXITY:
O(n log n)

→ map insertion: log n
→ n nodes processed once

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ queue + map storage

============================================================
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        queue<pair<Node * ,int>> q;
        map<int,vector<int>> mpp;
        vector<int> ans;

        if(!root) return ans;

        q.push({root,0});

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            Node *node=top.first;
            int level=top.second;

            mpp[level].push_back(node->data);

            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }

        for(auto it:mpp){
            ans.push_back(it.second[it.second.size()-1]); // last node
        }

        return ans;
    }
};



/*
============================================================
LEFT VIEW OF BINARY TREE (BFS + MAP)
============================================================

APPROACH:
- Use BFS traversal with queue storing:
    → node + level

- Maintain map<int, vector<int>>:
    → key = level
    → value = nodes in BFS order at that level

- For each node:
    → Insert node->data into mpp[level]
    → Push left child first, then right child

- Since BFS processes left → right:
    → First node at each level = left view

- Finally:
    → Traverse map in level order
    → Take first element of each level

------------------------------------------------------------

TIME COMPLEXITY:
O(n log n)

→ map insertion: log n
→ n nodes processed once

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ queue + map storage

============================================================
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        queue<pair<Node * ,int>> q;
        map<int,vector<int>> mpp;
        vector<int> ans;

        if(!root) return ans;

        q.push({root,0});

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            Node *node=top.first;
            int level=top.second;

            mpp[level].push_back(node->data);

            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }

        for(auto it:mpp){
            ans.push_back(it.second[0]); // first node
        }

        return ans;
    }
};
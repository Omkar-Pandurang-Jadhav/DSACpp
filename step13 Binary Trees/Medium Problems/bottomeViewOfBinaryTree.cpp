

/*

You are given the root of a binary tree, and your task is to return its bottom view.
 The bottom view of a binary tree is the set of nodes visible when the tree is viewed 
 from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, 
then the latter one in the level order traversal is considered.

Examples :

Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.*/
/*
============================================================
BOTTOM VIEW OF BINARY TREE (BFS + MAP)
============================================================

APPROACH:
- Use BFS traversal with queue storing:
    → node + column index (x)

- Maintain map<int, vector<int>>:
    → key = column (x)
    → value = nodes in BFS order for that column

- For each node:
    → Push its value into mpp[x]
    → Push left child with (x-1)
    → Push right child with (x+1)

- Since BFS processes level by level:
    → Last element in each column = bottom view node

- Finally:
    → Traverse map in sorted column order
    → Take last element of each column

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
    vector<int> bottomView(Node *root) {
        queue<pair<Node *,int>> q;
        q.push({root,0});

        map<int,vector<int>> mpp;
        vector<int> ans;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            Node * node=top.first;
            int x=top.second;

            mpp[x].push_back(node->data);

            if(node->left) q.push({node->left,x-1});
            if(node->right) q.push({node->right,x+1});
        }
        
        for(auto p:mpp){
            ans.push_back(p.second[p.second.size()-1]); // last node in BFS order
        }
        
        return ans;
    }
};

/*
Given the root of a binary tree, calculate the vertical order traversal of 
the binary tree.

For each node at position (row, col), its left and right children will be at positions
 (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at 
 (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for 
each column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, sort these 
nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.*/

/*
============================================================
VERTICAL ORDER TRAVERSAL (USING PRIORITY QUEUE)
============================================================

APPROACH:
- Perform DFS traversal
- For each node:
    → Store (column, row, value) in min heap
    → Column: horizontal distance
    → Row: depth
- Use priority_queue with ordering:
    → First by column
    → Then by row
    → Then by value (default pair behavior)
- Track maximum column (maxi)
- After traversal:
    → Get minimum column from heap top
    → Create result vector of size (maxi - min + 1)
    → Pop elements from heap and group by column

------------------------------------------------------------

TIME COMPLEXITY:
O(n log n)

→ Each insertion into priority queue: O(log n)
→ Total n insertions + n deletions

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Priority queue stores all nodes
→ Recursion stack O(h)

============================================================
*/

class Solution {
public:
    void traversal(TreeNode *root,
        priority_queue<pair<pair<int,int>,int>,
        vector<pair<pair<int,int>,int>>,
        greater<pair<pair<int,int>,int>>> & pq,
        int row,int col,int &maxi){

        if(!root) return;

        maxi = max(maxi, col);

        pq.push({{col,row},root->val});

        traversal(root->left,pq,row+1,col-1,maxi);
        traversal(root->right,pq,row+1,col+1,maxi);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        priority_queue<pair<pair<int,int>,int>,
        vector<pair<pair<int,int>,int>>,
        greater<pair<pair<int,int>,int>>> pq;

        int maxi = INT_MIN;

        traversal(root,pq,0,0,maxi);

        int min = pq.top().first.first;

        vector<vector<int>> ans(maxi - min + 1);

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int col = temp.first.first;
            int row = temp.first.second;
            int data = temp.second;

            ans[col - min].push_back(data);
        }

        return ans;
    }
};


/*
Given the root of a Binary Tree, find the vertical traversal of the tree starting 
from the leftmost level to the rightmost level.

Note: If there are multiple nodes passing through a vertical line, then they should
 be printed as they appear in level order traversal of the tree.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, N, 8, N, 9, N, 10, 11, N]
                    
Output: [[4], [2], [1, 5, 6, 11], [3, 8, 9], [7], [10]]
Explanation: The below image shows the horizontal distances used to print vertical 
traversal starting from the leftmost level to the rightmost level.

/*
============================================================
VERTICAL ORDER TRAVERSAL (GFG VERSION - BFS BASED)
============================================================

APPROACH:
- Use BFS traversal (level order)
- Maintain queue storing:
    → node + column index (x)

- Use map<int, vector<int>>:
    → key = column (x)
    → value = nodes in BFS order

- For each node:
    → Insert node->data into mpp[x]
    → Push left child with (x-1)
    → Push right child with (x+1)

- Finally:
    → Traverse map in sorted column order
    → Push each column's vector into answer

------------------------------------------------------------

TIME COMPLEXITY:
O(n log n)

→ map insertion takes log n
→ n nodes processed once

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ queue stores nodes
→ map stores all nodes

============================================================
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        queue<pair<Node *,int>> q;
        q.push({root,0});

        map<int,vector<int>> mpp;
        vector<vector<int>> ans;

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
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
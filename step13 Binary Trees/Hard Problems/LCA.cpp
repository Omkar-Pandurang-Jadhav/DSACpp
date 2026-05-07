/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
 in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
defined between two nodes p and q as the lowest node in T that has both p and q as 
descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
*/


/*
============================================================
LOWEST COMMON ANCESTOR (PATH BASED APPROACH)
============================================================

APPROACH:
- Find path from root → node p
- Find path from root → node q
- Store both paths in vectors
- Traverse both vectors from start:
    → Last common node in prefix = LCA

- Use DFS + backtracking to build path:
    → Add node to path
    → If target found → stop recursion
    → Else explore left/right
    → If not found → backtrack (pop)

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ DFS to find path for p: O(n)
→ DFS to find path for q: O(n)
→ Compare paths: O(n)
→ Total: O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Two vectors storing paths: O(n)
→ Recursion stack: O(h)
→ Total: O(n)

============================================================
*/

class Solution {
public:
    bool rootToLeafPaths(TreeNode *root,vector<TreeNode *> &temp,TreeNode* node){
       if(!root) return false;

       temp.push_back(root);

       if(root==node) return true;

       if(rootToLeafPaths(root->left,temp,node) || 
          rootToLeafPaths(root->right,temp,node)){
            return true;
       }

       temp.pop_back();
       return false;
   }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> temp1,temp2;

        rootToLeafPaths(root,temp1,p);
        rootToLeafPaths(root,temp2,q);

        TreeNode* ans=NULL;

        int i=0;
        while(i<temp1.size() && i<temp2.size()){
            if(temp1[i]==temp2[i]) ans=temp1[i];
            else break;
            i++;
        }
        
        return ans;
    }
};


/*
============================================================
LOWEST COMMON ANCESTOR (OPTIMAL DFS APPROACH)
============================================================

APPROACH:
- Use single DFS traversal
- For each node:
    → If node is NULL → return NULL
    → If node == p OR node == q → return node

- Recur for left and right subtree:
    → l = result from left subtree
    → r = result from right subtree

- Cases:
    → If l == NULL → return r
    → If r == NULL → return l
    → If both exist → current node is LCA

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited at most once

------------------------------------------------------------

SPACE COMPLEXITY:
O(h)

→ Recursion stack
→ h = height of tree
→ Worst case: O(n)
→ Best case: O(log n)

============================================================
*/

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l == NULL) return r;
        else if(r == NULL) return l;
        else return root;
    }
};
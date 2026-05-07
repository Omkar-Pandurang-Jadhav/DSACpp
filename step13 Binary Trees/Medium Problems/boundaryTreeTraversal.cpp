
/*
Given a root of a Binary Tree, return its boundary traversal in the following order:

Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left 
child over the right and excluding leaves.

Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring
 the right child over the left, excluding leaves, and added in reverse order.

Note: The root is included once, leaves are added separately to avoid repetition, and 
the right boundary follows traversal preference not the path from the rightmost leaf.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]*/
/*
============================================================
BOUNDARY TRAVERSAL OF BINARY TREE
============================================================

APPROACH:
- Add root node (if not leaf)
- Traverse left boundary:
    → Move down using left if possible, else right
    → Add non-leaf nodes only
- Add all leaf nodes using DFS (left → right)
- Traverse right boundary:
    → Move down using right if possible, else left
    → Store non-leaf nodes in temp
    → Add them in reverse order to result

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited at most once

------------------------------------------------------------

SPACE COMPLEXITY:
O(h)

→ Recursion stack for leaf traversal
→ h = height of tree
→ Worst case: O(n)
→ Best case: O(log n)

============================================================
*/

class Solution {
  public:
    bool isLeaf(Node *root){
        return (!root->left && !root->right);
    }

    void addLeft(Node* root,vector<int> &ans){
        Node *cur=root->left;
        while(cur){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }
    }
    
    void addRight(Node *root,vector<int> &ans){
        vector<int> temp;
        Node *cur=root->right;
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    
    void addLeaf(Node *root,vector<int> &ans){
        if(!root) return;

        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        addLeaf(root->left,ans);
        addLeaf(root->right,ans);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        ans.push_back(root->data);

        if(isLeaf(root)) return ans;

        addLeft(root,ans);
        addLeaf(root,ans);
        addRight(root,ans);
        
        return ans;
    }
};
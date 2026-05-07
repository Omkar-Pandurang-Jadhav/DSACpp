/*
============================================================
PREORDER TRAVERSAL (ITERATIVE)
============================================================

APPROACH:
- Use stack
- Push root
- Pop node → process it
- Push right first, then left (so left is processed first)

TIME COMPLEXITY:
O(n)

→ Each node is pushed and popped once

SPACE COMPLEXITY:
O(h)

→ Stack space (worst case O(n), best case O(log n))
*/

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->val);

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }

    return ans;
}



/*
============================================================
INORDER TRAVERSAL (ITERATIVE)
============================================================

APPROACH:
- Use stack and pointer
- Go left as much as possible
- Process node
- Move to right

TIME COMPLEXITY:
O(n)

→ Each node is visited once

SPACE COMPLEXITY:
O(h)

→ Stack space
*/

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != NULL || !st.empty()){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->val);

        curr = curr->right;
    }

    return ans;
}



/*
============================================================
POSTORDER TRAVERSAL (USING TWO STACKS)
============================================================

APPROACH:
- Use two stacks
- First stack: process nodes
- Second stack: reverse order
- Final order becomes postorder

TIME COMPLEXITY:
O(n)

→ Each node processed twice

SPACE COMPLEXITY:
O(n)

→ Two stacks used
*/

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);

        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}



/*
============================================================
POSTORDER TRAVERSAL (USING ONE STACK)
============================================================

APPROACH:
- Use one stack + pointer
- Traverse left first
- Check right subtree before processing node
- Use lastVisited to track processed nodes

TIME COMPLEXITY:
O(n)

→ Each node visited once

SPACE COMPLEXITY:
O(h)

→ Stack space
*/

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = NULL;

    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode* peek = st.top();

            if(peek->right != NULL && lastVisited != peek->right){
                curr = peek->right;
            }
            else{
                ans.push_back(peek->val);
                lastVisited = peek;
                st.pop();
            }
        }
    }

    return ans;
}
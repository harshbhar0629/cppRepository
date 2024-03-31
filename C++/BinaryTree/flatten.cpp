#include<bits./stdc++.h>
// #define prev NULL  
// O(N)
TreeNode* prev =NULL;
void flattenTree(TreeNode* root){
    if(root==NULL) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left =NULL;
    prev = root;
}

// O(N)
void flattenTreeIterative(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* curr;
    st.push(root);
    while(st.size()){
        curr =st.top();
        st.pop();
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
        if(st.size()) curr->right  = st.top();
        curr->left = NULL;
    }
}

// SC O(1)
void flattenTreeIterative(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
        if(curr->left){
            TreeNode* prev = curr->left;
            while(prev->right){
                prev =prev->right;
            }
            prev ->right = curr->right;
            curr->right = curr->left ;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}


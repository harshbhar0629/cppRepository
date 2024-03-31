#include<bits/stdc++.h>
using namespace std;
// step1  find ancestor b/w nodes and after find the distance between both of them

TreeNode* findAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL) return NULL;
    while(root){
        if(root->val > p->val and root->val > q->val) root = root->left;
        else if(root->val < p->val and root->val < q->val) root = root->right;
        else return root;
    }
    return NULL;
}

int search(TreeNode* root, TreeNode* p){
    if(root==NULL) return 0;
    int dis=0;
    while(root){
        if(root->val == p->val) return dis;
        if(root->val > p->val) root = root->left;
        else root = root->right;
        dis++;
    }
    return dis;
}
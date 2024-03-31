#include<bits/stdc++.h>
using namespace std;
class Solution {
        // TC O(N)  and   SC O(h)
    TreeNode* prev;
    TreeNode* mid; //if violation is in adjacent node
    TreeNode* first; //store first violation
    TreeNode* last; //last violation

    void recover(TreeNode* root){
        if(!root) return ;
        recover(root->left);
        if(prev and root->val < prev->val){

            // if violation is in adjacent nodes
            if(first == NULL){
                mid = root;
                first = prev;
            }
            else {
                last = root;
            }
        }
        prev = root;
        recover(root->right);
    }    

public:
    void recoverTree(TreeNode* root) {
        first = mid = last = NULL;
        prev = new TreeNode(INT_MIN);
        recover(root);

        if(first and last) swap(first->val , last->val); //if violation is not in adjacent  node
        else swap(first->val,mid->val);//if violation is in adjacent node
       
    }
};

**************************************************************************************************************************************

class Solution {
public:// TC O(N) and SC O(N)
    void inorder(vector<TreeNode*>& v,TreeNode* root){
        if(root==NULL) return;
        inorder(v,root->left);
        v.push_back(root);
        inorder(v,root->right);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*>v;
        inorder(v,root);

        int n = v.size();
        TreeNode* first=NULL;
        TreeNode* last = NULL;
        TreeNode* mid = NULL;

        for(int i=0;i<n-1;i++){
            if(v[i]->val > v[i+1]->val){
                if(first==NULL){
                    first = v[i];
                    mid = v[i+1];
                }
                else{
                    last = v[i+1];
                }
            }
        }
        
        if(first and last) swap(first->val,last->val);
        else swap(first->val,mid->val);
    }
};

****************************************************************************************************************************************

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = new TreeNode(INT_MIN) ;
        TreeNode* a = NULL; 
        TreeNode* b  = NULL; 
        TreeNode* curr = root;
        while(curr){
            if(curr->left == NULL){
                if(prev->val > curr->val){
                    if(a == NULL) {
                        a = prev;
                        b = curr;
                    }
                    else{
                        b = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
            else{
                TreeNode *t = curr->left;
                while(t->right and t->right != curr){
                    t = t->right;
                }

                if(t->right==NULL){
                    t->right = curr;
                    curr = curr->left;
                }
                else {
                    t->right = NULL;
                    if( prev->val > curr->val){
                        if(a == NULL) {
                            a = prev;
                            b = curr;
                        }
                        else{
                            b = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        swap(a->val,b->val);
    }
};

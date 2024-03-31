#include<bits/stdc++.h>

// vector<int> morrisTraversalPreorder(TreeNode* root){
//     vector<int> v;
//     TreeNode* curr = root;
//     while(curr){
//         if(curr->left==NULL){
//             v.push_back(curr->val);
//             curr= curr->right;
//         }
//         else{
//             TreeNode* prev = curr->left;
//             while(prev->right && prev->right !=curr){
//                 prev = prev->right;
//             }
//             if(prev->right==NULL){
//                 prev->right = curr;
//                 v.push_back(curr->val);
//                 curr= curr->left;
//             }
//             else{
//                 prev->right = NULL;
//                 curr= curr->right
//             }
//         }
//     }
//     return v;
// }


vector<int> morrisTraversalInorder(TreeNode* root){
    vector<int> v;
    TreeNode* curr = root;
    while(curr){
        if(curr->left==NULL){
            v.push_back(curr->val);
            curr= curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right !=curr){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right = curr;
                curr= curr->left;
            }
            else{
                prev->right = NULL;
                v.push_back(curr->val);
                curr= curr->right
            }
        }
    }
    return v;
}
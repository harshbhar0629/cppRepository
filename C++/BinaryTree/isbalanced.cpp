#include<bits/stdc++.h>
using namespace std;

// O(n^2)
// int heights(TreeNode* root){
//     if(root ==NULL) return 0;
//     return max(heights(root->left),heights(root->right))+1;
// }

// bool isBalanced(TreeNode* root){
//     if(root==NULL) return true;
//     bool left = isBalanced(root->left);
//     bool right = isBalanced(root->right);
//     if(!right || !left) return false;
//     int a= heights(root->right);
//     int b= heights(root->left);
//     if(abs(a-b) > 1) return false;
//     return true;
// }

// O(N)
int check(TreeNode* root,bool ans){
    if(root ==NULL) return 0;
    if(!ans) return 0;
    int left = check(root->left,ans);
    int right = check(rooot->right,ans);
    if(abs(left-right)>1) ans = false;
    return 1+max(left,right);
}

bool isBalanced(TreeNode* root){
    bool ans = true;
    check(root,ans);
    return ans;

}

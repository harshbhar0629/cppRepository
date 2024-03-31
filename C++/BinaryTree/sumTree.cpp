// sum of root data is equal to its sum of child data
#include<bits/stdc++.h>
using namespace std;

// pair<bool,int> check(TreeNode* root){
//     if(root==NULL) {
//         pair<bool,int> p = make_pair(true,0);
//         return p;
//     }
//     if(root->left==NULL and root->right==NULL){
//         pair<bool,int> p= make_pair(true,root->val);
//         return p;
//     }
//     pair<bool,int> left = check(root->left);
//     pair<bool,int> right = check(root->right);
//     bool condition = left.second + right.second == root->data;
//     pair<bool,int> ans;
//     if(left.first and right.first and condition){
//         ans.first = true;
//         ans.second = 2*root->val;
//     }
//     else{
//         ans.first= false;
//     }
//     return ans;
// }


// bool checkSum(treeNode* root){
//     return check(root).first;
// }

bool flag = true;
int checkSumTree(treeNode* root,bool flag ){
    if(root==NULL) return 1;
    if(!flag) return 0;
    int a = checkSumTree(root->left,flag);
    int b = checkSumTree(root->right,flag);
    if(a+b!=root->data){
        flag = false;
    }
    return a+b+root->data;

}

int main(){

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int heights(treeNode* root){
    if(root==NULL) return 0;
    int op1 = heights(root->left);
    int op2 = heights(root->right);
    int ans = max(op1,op2)+1;
    return ans;
}

int main(){

    return 0;
}
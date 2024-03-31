#include<bits/stdc++.h>
using namespace std;

bool countNodeInRange(TreeNode* root,int lo,int hi,int& count){
    if(root==NULL) return true;
    bool left = countNodeInRange(root->left,lo,hi,count);
    bool right = countNodeInRange(root->right,lo,hi,count);
    if(left and right and root->val <= lo and root->val >= hi){
        count++;
        return true;
    }
    else return false;
}

int main(){
    int count=0;
    countNodeInRange(root,lo,hi,count);
    
    cout<<count
    
}
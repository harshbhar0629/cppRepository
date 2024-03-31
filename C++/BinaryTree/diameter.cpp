#include<bits/stdc++.h>
using namespace std;

int heights(treeNode* root){
    if(root==NULL) return 0;
    return max(heights(root->left),heights(root->right))+1;
}
// o(n^2) ans sc=(o(N))
int diameter(treeNode* root ,int &ans){
    if(root==NULL) return 0;
     int left = diameter(root->left);
    int right = diameter(root->right);
    int possible = heights(root->left) + heights(root->right) + 1;
    int ans = max(possible,max(right,left));
    return ans;
}
 
// O(N)time solution O(N) space 
pair<int,int> diameterFast(Treenode* root){
    if(root==NULL){
        pair<int,int>p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right); 
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.first + 1 + right.first ;
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3)); //it will store diameter 
    ans.second = max(left.second, right.second);//it will store height
    return ans;
}

// o(n);
int diameter(treeNode* tree,int ans){
    if(root==NULL) return 0;
    int left = diameter(root->left);
    int right = diameter(root->right);
    ans = max(ans,left+right)+1;
    return max(left,right);
}
int main(){

    return 0;
}
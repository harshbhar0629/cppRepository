// traverse all boundary in a tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverseLeft(TreeNode *root, vector<int>& ans)
{
    if (root == NULL || root->left == NULL and root->right == NULL)  return;
    
    ans.push_back(root->val);
    if (root->left) traverseLeft(root->left, ans);
    else traverseLeft(root->right, ans);
}

void traverseLeaf(TreeNode *root, vector<int>& ans)
{
    if (root == NULL)return;
    if (root->left == NULL and root->right == NULL) {
        ans.push_back(root->val);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode* root,vector<int>& ans){
    if(root==NULL || root->left==NULL and root->right==NULL) return;

    if(root->right) {
        traverseRight(root->right,ans);
    }
    else {
        traverseRight(root->left,ans);
    }
    ans.push_back(root->val);
}

vector<int> traverseBoundary(TreeNode *root)
{
    if (root == NULL)  return {};
    
    vector<int> ans;

    // first step to store root
    ans.push_back(root->val);

    // step 2 traverse left boundary from up to down
    traverseLeft(root->left, ans);

    // step 3 traverse all leaf node by apply inorder traversal
    // a: traverse all leaf node from left
    traverseLeaf(root->left, ans);
    // b: traverse all leaf node from right
    traverseLeaf(root->right, ans);

    // step 4 traverse right boundary
    traverseRight(root->right, ans);

    return ans;
}


TreeNode* f(TreeNode* root){
    int d;
    cout<<"Enter Data: ";
    cin>>d;
    root = new TreeNode(d);
    if(d==0 || d==-1) return NULL;
    cout<<"Enter left data of "<<d<<endl;
    root->left = f(root->left);
    cout<<"Enter right data of "<<d<<endl;
    root->right = f(root->right);

    return root;
}



int main(){
    TreeNode*  root= NULL;
    root = f(root);

    vector<int> ans = traverseBoundary(root);

    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}
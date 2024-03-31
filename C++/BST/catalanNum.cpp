#include<bits/stdc++.h>
using namespace std;
int catalan(int n){
    if(n==0 || n==1) return 1;
    int res=0;
    for(int i=0;i<n;i++){
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}
int main(){
    int n =7;
    for(int i=0;i<n;i++){
        cout<<catalan(i)<<"  ";
    }
}

**************************************************************************************************************************************

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> uniqueTrees(int s ,int e){
        if(s>e) return {NULL};
        vector<TreeNode*> list;
        for(int i=s ;i<=e;i++){
            vector<TreeNode*> leftSubTree = uniqueTrees(s,i-1);
            vector<TreeNode*> rightSubTree = uniqueTrees(i+1,e);
            for(auto leftTree : leftSubTree){
                for(auto rightTree : rightSubTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    list.push_back(root);
                }
            }
        }
        return list;
    }

    vector<TreeNode*> generateTrees(int n) {
        return uniqueTrees(1,n);
    }
};
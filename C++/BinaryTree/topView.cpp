#include<bits/stdc++.h>
#include<map>
using namespace std;

vector<int> topView(TreeNode* root){
    if(root== NULL) return {};
    vector<int> ans;
    queue<pair<TreeNode*,int>> q;
    map<int,int> m;
    q.push(make_pair(root,0));

    while(q.size()>0){
        pair<TreeNode*,int> p = q.front();
        q.pop();
        int currCol = p.second;
        TreeNode* t= p.first;
        if(m.find(currCol) == m.end()){
            m[currCol] = t->val;
        }

        if(t->left) q.push(make_pair(t->left,currCol-1));
        if(t->right) q.push(make_pair(t->right,currCol+1));
    }
    for(auto it : m){
        ans.push_back(it.second);
    }
}

int main(){

    return 0;
}


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

    vector<int> topView(TreeNode* root) {
        queue<pair<treeNode*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(q.size()){
            auto it = q.front();
            q.pop();
            int currCol = it.second;
            TreeNode *t = it.first;
            if(mp.find(currCol)==mp.end()){
                mp[currCol] = t->val;
            }
            if(t->left){
                q.push({t->left,currCol-1});
            }
            if(t->right){
                q.push({t->right,currCol+1});
            }
        }
        vector<int> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

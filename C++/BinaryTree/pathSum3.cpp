#include <bits/stdc++.h>
using namespace std;


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
#define ll long long int
class Solution {
    
    ll res = 0;
    bool flag = false;
    unordered_map<int,int>mp;
    void f(TreeNode* root, ll& target, ll sum){
        if(!root) return;
        sum+=root->val;
        if(root->val == 0 || sum==0) flag = true;
        if(sum==target) res++;

        res+=mp[sum-target];
        mp[sum]++;
        f(root->left, target, sum);
        f(root->right, target, sum);
        mp[sum]--;
    }

    // O(N^2)
    ll ans =0;
    void f(TreeNode* root, ll& target){
        if(!root) return;
        if(target==root->val) ans++;
        
        f(root->left, target-root->val);
        f(root->right, target-root->val);
    }

    ll dfs(TreeNode* root, ll& target){
        if(!root) return 0;
        f(root, target);
        dfs(root->left, target);
        dfs(root->right, target);
        return ans;
    }

public:
    ll pathSum(TreeNode* root, ll targetSum) {

        // O(N^2)
        if(!root) return 0;
        // dfs(root, targetSum);
        // return ans;

        // O(N)
        f(root, target, 0);
        if(!flag and targetSum==0) return 0;
        return res;

    }
};


int main(){
    

    return 0;
}
#include<bits/stdc++.h>

int findMaxDis(map<TreeNode*,TreeNode*> mp , TreeNode* target){
    queue<TreeNode*> q;
    q.push(target);
    map<TreeNode*,int> vis;
    vis[target] = 1;
    int maxi =0;
    while(q.size()){
        int size =q.size();
        bool flag = false;
        for(int i=0;i<size;i++){
            TreeNode* root = q.front();
            q.pop();
            if( root->left && !vis[root->left]){
                q.push(root->left);
                vis[root->left]=1;
                flag =true;
            }
            if(root->right and !vis[root->right]){
                q.push(root->right);
                vis[root->right]=1;
                flag = true;
            }
            if(mp[root] && !vis[mp[root]]){
                vis[mp[root]] =1;
                q.push(mp[root]);
                flag = true;
            }
        }
        if(flag) maxi++;
 
    }
    return maxi;

}



TreeNode* BfsToMap(TreeNode* root, int start,map<TreeNode*,TreeNode*>& mp){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res ;

    while(q.size()){
        root= q.front();
        if(root->data==start) res = root;
        q.pop();
        if(root->left){
            q.push(root->left);
            mp[root->left] = root;
        }
        if(root->right){
            q.push(root->right);
            mp[root->right] = root;
        }
    }
    return res;

}


int MinTimeToBurn(TreeNode* root, int start){
    map<TreeNode*,TreeNode*> mp;
    TreeNode* target = BfsToMap(root,start,mp);
    int maxi - findMaxDis(taregt,mp);
    return maxi;

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
    int findMaxDis(map<TreeNode*,TreeNode*> mp , TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*,int> vis;
        vis[target] = 1;
        int maxi =0;
        while(q.size()){
            int size =q.size();
            bool flag = false;
            for(int i=0;i<size;i++){
                TreeNode* root = q.front();
                q.pop();
                if(root->left and !vis[root->left]){
                    q.push(root->left);
                    vis[root->left]=1;
                    flag =true;
                }
                if(root->right and !vis[root->right]){
                    q.push(root->right);
                    vis[root->right]=1;
                    flag = true;
                }
                if(mp[root] && !vis[mp[root]]){
                    vis[mp[root]] =1;
                    q.push(mp[root]);
                    flag = true;
                }
            }
            if(flag) maxi++;
    
        }
        return maxi;

    }

    TreeNode* BfsToMap(TreeNode* root, int start,map<TreeNode*,TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res ;

        while(q.size()){
            root= q.front();
            if(root->val==start) res = root;
            q.pop();
            if(root->left){
                q.push(root->left);
                mp[root->left] = root;
            }
            if(root->right){
                q.push(root->right);
                mp[root->right] = root;
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mp;
        TreeNode* target = BfsToMap(root,start,mp);
        int time = findMaxDis(mp,target);
        return time;
    }
};
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
    void solve(vector<int> &ans,TreeNode* root,int& level){
        if(root==NULL) return ;
        if(level == ans.size()) ans.push_back(root->val);
        solve(ans,root->right,level+1);
        solve(ans,root->left,level+1);
    }

    void LEvelOrder(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int size=q.size();
            bool f = true;
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if(f) {
                    ans.push_back(temp->val);
                    f = false;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
               
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        solve(ans,root,0);
        return ans;
    }
};


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
    void solve(vector<int> &ans,TreeNode* root,int level){
        if(root==NULL) return;
        if(ans.size()==level){
            ans.push_back(root->val);
        } 
        solve(ans,root->left,level+1);
        solve(ans,root->right,level+1);
    }

    void LEvelOrder(TreeNode* root,vector<int>& ans){
        queue<TreeNode*> q;
        if(root==NULL) return;
        q.push(root);
        while(q.size()>0){
            int size=q.size();
            while(size--){
                root = q.front();
                q.pop();
                if(size==0) ans.push_back(root->val);
                if(root->right) q.push(root->right);
                if(root->left) qq.push(root->left);
            }
        }

    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        solve(ans,root,0);
        return ans;
    }
};
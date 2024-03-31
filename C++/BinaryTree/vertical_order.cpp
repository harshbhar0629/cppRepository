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
    // if element aare in random order then prefer this.. 
    void help(map<int,vector<int>>& mp , TreeNode* root, int level){
        if(root==NULL){
            return;
        }
        mp[level].push_back(root->val);
        help(mp,root->left,level-1);
        help(mp,root->right, level+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        help(mp,root,0);
        vector<vector<int>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }

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
    // if maintaining the increasing order then prefer this recursion;
    
    void help( map<int, map<int ,<multiset<int>>> &mp , TreeNode* root, int row,col){
        if(root==NULL) return;
        mp[col][row].insert(root->val);
        help(mp,root->left,row+1,col-1);
        help(mp,root->right,row+1,col+1);
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int ,<multiset<int> > > mp;
        help(mp,root,0,0);
        
        vector<vector<int>> ans;

        for(auto it : mp){
            vector<int> v;
            for(auto p : it.second){
                v.insert(v.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(v);
        }

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
    // if maintaining the increasing order then prefer this level order traversal;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int ,<multiset<int> > > mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(q.size()){
            auto it = q.front()
            q.pop();
            TreeNode* t= it.first;
            int x = it.second.first , y = it.second.second;
            mp[x][y].insert(t->val);
            if(t->left){
                q.push({t->left,{x-1,y+1}});
            }
            if(t->right){
                q.push({t->right,{x-1,y+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto it : mp){
            vector<int> v;
            for(auto p : it.second){
                v.insert(v.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(v);
        }

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
    // if maintaining the increasing order then prefer this level order traversal;
    
    vector<int> verticalTraversalSum(TreeNode* root) {
        map<int , int> mp;
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            auto it = q.front();
            q.pop();
            TreeNode* t= it.first;
            int x = it.second;
            mp[x]= m[x]+ t->val;
            if(t->left) q.push({t->left,x-1});
            if(t->right) q.push({t->right,x+1});
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
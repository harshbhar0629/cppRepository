// k sum path , transfor sum tree,
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
class Solution
{
public:
    // if maintaining the increasing order then prefer this level order traversal;

    vector<int> verticalTraversal(TreeNode *root)
    {
        unordered_map<int, int> mp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (q.size() > 0)
        {
            auto it = q.front();
            q.pop();
            TreeNode *t = it.first;
            int level = it.second;
            mp[level] = t->val;
            if (t->left)
                q.push({t->left, level - 1});
            if (t->right)
                q.push({t->right, level + 1});
        }

        vector<int> ans;

        for (auto it : mp)
        {
            // ans.push_back(it.second);
            cout << it.second << " ";
        }

        return ans;
    }
};


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
    TreeNode* root = NULL;
    root = f(root);
    Solution s;
    s.verticalTraversal(root);

    return 0;
}
// 1 2 4 8 0 0 9 0 0 5 0 0 3 6 0 0 7 10 0 0 11 0 0
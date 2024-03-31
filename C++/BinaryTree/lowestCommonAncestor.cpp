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
class solution{
public: 
    // O(N^2) 
    bool exist(TreeNode* root,TreeNode* p){
        if(root==NULL) return false;
        if(root==p) return true;
        return exist(root->left,p) || exist(root->right,p);
    }

    TreeNode* lowestAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==p or root==q) return root;
        if(p==q) return p;
        bool left = exist(root->left,p);
        bool right = exist(root->right,q);
        if(left and right ) return root;
        else if(!left and !right) return root;
        else if(!left and right) return lowestAncestor(root->right,p,q);
        else lowestAncestor(root->left ,p,q); 
    }

    // O(N)
    TreeNode* lowestAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==p or root==q) return root;
        if(root==NULL) return NULL;
        TreeNode*  left = lowestAncestor(root->left,p,q);
        TreeNode* right = lowestAncestor(root->right,p,q);
        if(left and right ) return root;
        else if(!left and right) return right;
        else if(left and !right) return left;
        else return NULL; 
    }

};
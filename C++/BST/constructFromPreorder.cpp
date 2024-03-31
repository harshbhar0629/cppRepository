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
public: //O(n Logn)
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int n = arr.size();
        TreeNode* root = new TreeNode(arr[0]);
        for(int i=1;i<n;i++){
            TreeNode* t= root;
            bool flag = false;
            while(!flag){
                if(t->val > arr[i]){
                    if(t->left){
                        t=t->left;
                    }
                    else{
                        t->left = new TreeNode(arr[i]);
                        flag = true;
                    }
                }
                else{
                    if(t->right){
                        t = t->right;
                    }
                    else{
                        t->right = new TreeNode(arr[i]);
                        flag = true;
                    }
                }
            }
        }
        return root;
    }
};

// where m is lower bound and n is upper bound
TreeNode* solve(vector<int> &v,int m,int n,int &i){
    if(i>=v.size()) return NULL;
    if(v[i]<m || v[i] > n) return NULL;
    TreeNode* root = new TreeNode(v[i++]);
    root->left = solve(v,m,root->data,i);
    root->right = solve(v,root->data,n,i);
    return root;

}


TreeNode* constructTreeFromPre(vector<int>&v){
    int maxi=INT_MAX,mini=INT_MIN;
    return solve(v,mini,maxi,0);
}
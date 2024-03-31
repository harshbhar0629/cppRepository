/*
Given Postorder and Inorder traversals, construct the tree.

Examples: 

Input: 
in[]   = {2, 1, 3}
post[] = {2, 3, 1}

Output: Root of below tree

      1
    /   \
   2     3 

Input: 
in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1} 

Output: Root of below tree

           1
        /     \
     2        3
  /    \    /   \
4     5   6    7
  \
   8
*/
class solution{
public://O(n^2)
    TreeNode* solve(vector<int> &in ,vector<int>&post,int &start,int s, int e){
        if(s>e || start < 0) return NULL;
        TreeNode* root = new TreeNode(post[start--]);
        if(s==e) return root;
        int idx=0;
        while(idx<=e){
            if(in[idx]==root->val) break;
            idx++;
        }
        root->right = solve(in,pre,start,idx+1,e);
        root->left = solve(in,post,start,s,i-1);
        return root;
    }

    TreeNode* constructTree(vector<int> &in ,vector<int>&post){
        TreeNode* ans = solve(in,post,in.size()-1,0,in.size()-1);
        return ans;
    }


    // use mapping O(N)
    void createMapping(vector<int>& in, map<int,int>& mp){
        for(int i=0;i<in.size();i++){
            mp[in[i]]= i;
        }
    }
    TreeNode* solve(vector<int> &in ,vector<int>&post,int start,int s, int e,map<int,int> &mp){
        if(s>e || start < 0) return NULL;
        TreeNode* root = new TreeNode(post[start--]);
        if(s==e) return root;
        int idx = mp[post[start]]; //find element in O(1) operation 
        root->right = solve(in,pre,start,idx+1,e);
        root->left = solve(in,post,start,s,i-1);
        return root;
    }

    TreeNode* constructTree(vector<int> &in ,vector<int>&post){
        map<int,int> mp;
        createMappping(in,mp);
        TreeNode* ans = solve(in,post,in.size()-1,0,in.size()-1,mp);
        return ans;
    }
};
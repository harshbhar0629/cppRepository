/*Construct Tree from Inorder & Preorder
MediumAccuracy: 34.59%Submissions: 128K+Points: 4
Save 25% On Your Favorite Courses & Get Additional Cashback. Explore Offers Now

Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000
*/

class solution{
public://O(n^2)
    TreeNode* solve(vector<int>& pre , vector<int>& in,int pstart,int pend,int start, int end){
       if(start>end || pstart>=in.size()) return NULL;
       TreeNode* root = new TreeeNode(pre[pstart]);
       int idx=start;
       while(idx<=end){
            if(pre[pstart] == in[idx]) break;
       }
       int leftCount = idx - start;
       root->left = solve(pre,in,pstart+1,pstart+leftCount,start,idx-1);
       root->right = solve(pre,in,pstart+leftCount+1,pend,idx+1,end);
       return root;
    }
    TreeNode* constructTree(vector<int>& pre , vector<int>& in){
        TreeNode* ans = solve(pre, in, 0, 0 ,in.size()-1);
        return ans;
    }



    // by using map O(n)
    void createMap(vector<int>& in,map<int,int>& m){
        for(int i=0;i<in.size();i++){
            m[in[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& pre , vector<int>& in,int & pstart,int pend,int start, int end,map<int,int>&mp){
        if(start>end || pstart>=in.size() ) return NULL;

        TreeNode* root= new TreeNode(pre[pstart]);
        int idx = mp[pre[pstart]]; //O(1)
        int leftCount = idx- start;
       
        root->left = solve(pre,in,pstart+1,pstart+leftCount,start,idx-1,m);
        root->right = solve(pre ,in,pstart+leftCount+1,pend,idx+1,end,m);
        return root;
    }

    TreeNode* constructTree(vector<int>& pre , vector<int>& in){
        map<int,int> mp;
        createMap(in,mp);
        
        TreeNode* ans = solve(pre, in, 0, in.size(),0 ,in.size()-1,mp);
        return ans;
    }
};
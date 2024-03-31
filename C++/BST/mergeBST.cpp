// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
//     TreeNode* inorderToBst(vector<int> & v,int s ,int e){
//         if(s>e) return root;
//         int mid = (s+e)/2;
//         TreeNode* root = new TreeNode(v[mid]);
//         root->left = inorderToBst(v,s,mid-1);
//         root->right = inorderToBst(v,mid+1,e);
//         return root;
    
//     }


//     void inorder(vector<int>& v,TreeNode* root){
//         if(root==NULL) return;
//         inorder(v,root->left);
//         v.push_back(root->val);
//         inorder(v,root->right);
//     }

//     vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
//         vector<int> v1,v2;
//         inorder(v1,root1);
//         inorder(v2,root2);
//         vector<int> ans;
//         int i=0,j=0;
        
//         while(i < v1.size() and j < v2.size()){
//             if(v1[i] < v2[j]){
//                 ans.push_back(v1[i++]);
//             }
//             else {
//                 ans.push_back(v2[j++]);
//             }
//         }

//         while(i < v1.size()){
//             ans.push_back(v1[i++]);
//         }

//         while(j < v2.size()){
//             ans.push_back(v2[j++]);
//         }
//         return ans;

//         // if you want to return a balance bst then by using inorder make bst..
//         // TreeNode* a = inorderToBst(ans,0,ans.size()-1);

//     }


// merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ans)); 
// Merge function takes log(m+n) as compared with sort function which takes nlogn time. 
// return ans;

//***********************************************************************************************************************************************
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
      public:                              
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    TreeNode* merge(TreeNode* a ,TreeNode*b){
        TreeNode* dummy = new TreeNode(1);
        TreeNode* temp = dummy;
        while(a and b){
            if(a->val < b->val){
                temp->right = a;
                a = a->right;
                temp = temp->right;
            }
            else{
                temp->right = b;
                b= b->right;
                temp = temp->right;
            }
        }
        if(a) temp->right = a;
        else temp->right =b;
        return dummy->right;
    }

   
    TreeNode* getAllElements(TreeNode* root1, TreeNode* root2) {
        // BstToDLL(root2);
        // BstToDLL(root1);

        // TreeNode* ans = merge(root1,root2);

        // while(ans){
        //     cout<<ans->val<<"  ";
        //     ans = ans->right;
        // }
        return root1;

    }
   
    void BstToDLL(TreeNode* root,TreeNode*& pre){
        cout<<"Hi"<<endl;
        if(!root) return ;
        BstToDLL(root->left,pre);
        root->left = pre;
         if(pre) pre->right = root;
        pre = root;
        BstToDLL(root->right,pre);
    }

    int main(){
        TreeNode* root1 = new TreeNode(2);
        root1->left = new TreeNode(1);
        root1->right = new TreeNode(3);
        // root1->left->left = NULL;
        // root1->left->right = NULL;
        // root1->right->left = NULL;
        // root1->right->right = NULL;
        // TreeNode* root2 = new TreeNode(1);
        // root2->left = new TreeNode(0);
        // root2->right = new TreeNode(3);
        // root2->right->left = NULL;
        // root2->right->left = NULL;
        // root2->left->left = NULL;
        // root2->left->right = NULL; 
        // TreeNode* ans = getAllElements(root1,root2);
         TreeNode* pre= NULL;
        BstToDLL(root1,pre);
        while(root1){
            cout<<root1->val<<" ";
            root1 = root1->right;
        }
        cout<<endl;
    }
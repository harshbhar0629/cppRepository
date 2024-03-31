#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v),left(NULL) ,right(NULL) {};

};

int minValue(Node* root){
    Node* t= root;
    while(t->left){
        t = t->left;
    }
    return t->val;
}

int maxValue(Node* root){
    Node* t= root;
    while(t->right){
        t= t->right;
    }
    return t->val;
}

Node* deleteInBST(Node* root,int val){
    if(root==NULL) return NULL;
    if(root->val == val){
        // 0 child
        if(!root->left and !root->right){
            delete root;
            return NULL;
        }

        // 1 child
        //  for left
        if(root->left and !root->right){
            Node* t= root->left;
            delete root;
            return t;
        }
        if(root->right and !root->left){
            Node* t = root->right;
            delete root;
            return t;
        }

        // 2 child
        // 2 option left m se max value le aao ya fir right m s min value le aao
        if(root->right and root->left){
            int mini = minValue(root->right);
            root->val = mini;
            root->right = deleteInBST(root->right,mini);
            return root;
        }

    }
    else if( root->val > val){
        deleteInBST(root->left,val);
    }
    else{
        deleteInBST(root->right,val);
    }
}
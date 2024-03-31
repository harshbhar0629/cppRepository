#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(){
        right=left=NULL;
    }
    node(int data){
        this->data = data;
        right=left=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new node(data);
    if(data==0 || data==-1){
        return NULL;
    }

    cout<<"enter data for inserting in left: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right: "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void inOrder(node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<"  ";
    inOrder(root->right);
}

void preOrder(node* root){
    if(root==NULL) return;
    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"  ";
}

int main(){
    //   1 3 7 0 0 11 0 0 5 17 0 0 0 

    node* root;
    root= buildTree(root);
    //     1 
    //   3    5
    // 7  11   17
    // inOrder(root); //o/p -> 7 3 11 1 17 5
    // preOrder(root);  //o/p -> 1 3 7 11 5 17
    postOrder(root); // o/p-> 7 11 3 17 5 1 

    return 0;
}
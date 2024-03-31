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

void postOrder(node* root , int& count){
    if(root == NULL) return;
    postOrder(root->left,count);
    postOrder(root->right,count);
    if(root->left==NULL and root->right==NULL) count++;

}

int main(){
    //   1 3 7 0 0 11 0 0 5 17 0 0 0 

    node* root;
    root= buildTree(root);
    int count=0;
    postOrder(root,count); // o/p-> 7 11 3 17 5 1 
    cout<<endl<<"leaf node : "<<count;
    return 0;
}
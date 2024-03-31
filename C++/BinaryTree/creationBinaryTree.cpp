#include<bits/stdc++.h>
using namespace std;

class node{
public: 
    int data;
    node* right;
    node* left;
    node(int data){
        this->data = data;
        right = left = NULL;
    }
};

node* buildTree(node* root){
    cout<<"enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    
    if(data == -1 || data==0) return NULL;

    cout<<"enter data for inserting in left of  "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right of  "<<data<<endl;
    root->right =  buildTree(root->right);
    
    return root;
}

void display(node* tree){
    if(tree==NULL) return ;
    cout<<tree->data<<" ";
    display(tree->left);
    display(tree->right);
}

int main(){

    node* root = NULL;

    root = buildTree(root);
    display(root);

    return 0;
}
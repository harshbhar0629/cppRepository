#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v),left(NULL) ,right(NULL) {};

};

void insertInToBST(Node* &root, int data)
{
    if (root == NULL)  {
        root = new Node(data);
        return;
    }
    if (root->val > data) {
        insertInToBST(root->left, data);
    }
    else  {
        insertInToBST(root->right, data);
    }
}

void createBST(Node *&root){
    // cout<<"hi";
    int data;
    cin >> data;
    while(data != -1) {
        insertInToBST(root, data);
        cout << "enter data: " << endl;
        cin >> data;
    }
}

void printBST(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* t =q.front();
            q.pop();
            cout<<t->val<<"  ";
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        cout<<endl;
    }   
}

void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" " ;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->val<<"  ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<"  ";
}


int main(){

    Node* root=NULL;
    cout<<"enter data for BST: "<<endl;
    createBST(root);
    printBST(root);
    cout<<endl;
    cout<<"Pre order "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"In order "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"post order "<<endl;
    postOrder(root);


}
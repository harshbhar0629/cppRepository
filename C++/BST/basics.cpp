#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node() : right(NULL), left(NULL){};
    Node(int v) : val(v), left(NULL), right(NULL){};
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

// int main(){
//     Node *root =NULL;
//     cout << "Enter data for BST" << endl;
//     createBST(root);
//     printBST(root);
//     return 0;
// }

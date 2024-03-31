#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* right;
    node*left;
    node(int data){
        this->data = data;
        right= left =NULL;
    }
};

node* buildTree(node *root){
    cout<<"enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data==0||data==-1) return NULL;
    
    cout<<"enter the data inseting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter the data inseting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void printTreeLinear(node* root){
    queue<node*>q;
    q.push(root);
    // q.push(NULL);

    while(q.size()>0){
        node* temp = q.front();
        q.pop();
        cout<<temp->data<<"  ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

void printTree(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(q.size()>0){
        node *temp= q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(q.size()>0){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<"  ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    // 1 2 4 0 0 5 0 0 3 6 0 0 7 0 0 

    node* root = NULL;
    root = buildTree(root);
    cout<<"\n linear tree: ";
    printTreeLinear(root);
    cout<<endl;
    cout<<"2D form tree: \n";
    printTree(root);

    return 0;
}
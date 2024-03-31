#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
    Tree() : left(NULL), right(NULL){};
    Tree(int val)
    {
        this->val = val;
        right = left = NULL;
    }
};

// Conditions - maxHeap: parent > child
bool isBtMaxHeap(Tree* root){
    queue<Tree *> q;
    q.push(root);

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr->left){
            if(curr->val < curr->left->val){
                return false;
            }
            q.push(curr->left);
        }
        if(curr->right){
            if(curr->val < curr->right->val){
                return false;
            }
            q.push(curr->right);
        }
    }

    //if we safely compute or check all the stuff then i'm sure this is a valid maxHeap
    return true;
}

int main(){


    return 0;
}
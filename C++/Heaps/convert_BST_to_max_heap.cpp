#include <bits/stdc++.h>
using namespace std;

class Tree{
public:
    int val;
    Tree* left;
    Tree* right;
    Tree(): left(NULL), right(NULL){};
    Tree(int val){
        this->val = val;
        right = left = NULL;
    }
};

void convertBstMaxHeap(Tree* root, vector<int>& res){
    if(root == NULL){
        return;
    }

    convertBstMaxHeap(root->right, res);
    res.push_back(root->val);
    convertBstMaxHeap(root->left, res);
}

int main(){
    

    return 0;
}
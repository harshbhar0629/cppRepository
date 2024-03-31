#include<bits/stdc++.h>
using namespace std;
class NodeValue{
public:
    int maxValue;
    int maxSize;
    int minValue;
    NodeValue(int minValue,int maxValue,int size){
        this->maxSize = size;
        this->minValue = minValue;
        this->maxValue = maxValue;
    }
};

NodeValue LargestBstHelper(TreeNode* root){
    if(root==NULL){
        return NodeValue(INT_MAX,INT_MIN,0);
    }
    auto left = LargestBstHelper(root->left);
    auto right = LargestBstHelper(root->right);
    if(left.maxValue < root->val and root->val < right.minValue ){
        int size = 1 + left.maxSize + right.maxSize;
        return NodeValue(min(left.minValue,root->val) , max(root->val,right.maxValue), size);
    }
    return NodeValue(INT_MIN,INT_MAX, max(left.maxSize,right.maxSize));
}
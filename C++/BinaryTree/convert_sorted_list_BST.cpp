// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* f(ListNode*& head, int n){
    if(head == NULL || n<=0) return NULL;
    TreeNode* leftTree = f(head, n-1-n/2);
    TreeNode* root = new Treenode(head->val);
    root->left = leftTree;
    head = head->next;
    root->right = f(head, n/2);
    return root;
}


TreeNode* sortedListToBST(ListNode* head){
    if(head == NULL) return NULL;
    int n =0;
    ListNode* t = head;

    while(t){
        n++;
        t = t->next;
    }
    return f(head, n);
}


int main(){
    

    return 0;
}
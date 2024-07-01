#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/make-binary-tree/1

// The structure of Link list Node is as follows 
struct Node{
    int data;
    struct node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// The structure of TreeNode is as follows 
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    
};

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root)
{
    if (!head)
        return;
    root = new TreeNode(head->data);
    queue<TreeNode *> q;
    q.push(root);
    Node *curr = head->next;

    while (!q.empty() and curr)
    {
        auto c = q.front();
        q.pop();
        c->left = new TreeNode(curr->data);
        q.push(c->left);
        curr = curr->next;

        if (!curr)
            break;
        c->right = new TreeNode(curr->data);
        q.push(c->right);
        curr = curr->next;
    }

    return;
}

int main()
{

    return 0;
}
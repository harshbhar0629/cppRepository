// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root) return root;
        Node* curr = root;

        while(curr){
            if(curr->left){
                Node* t = curr;
                while(t){
                    t->left->next = t->right;
                    t->right->next = (t->next == NULL)? NULL: t->next->left;
                    t = t->next;
                }
            }
            curr = curr->left;
        }
        return root;
        
        // Node* t = new Node(INT_MIN);
        // queue<Node*>q;
        // q.push(root);
        // q.push(t);
        // if(root==NULL) return NULL;

        // while(!q.empty()){
        //     int sz = q.size();
        //     for(int i=0; i<sz-1; i++){
        //         Node* r = q.front();
        //         q.pop();
        //         if(q.front()->val != INT_MIN){
        //             r->next = q.front();
        //         }
                
        //         if(r->left) q.push(r->left);
        //         if(r->right) q.push(r->right);
        //     }
        //     if(q.front()->val==INT_MIN){
        //         q.pop();
        //         if(q.size()>0) q.push(t);
        //     }
        // }
        // return root;
    }
};

int main(){
    

    return 0;
}
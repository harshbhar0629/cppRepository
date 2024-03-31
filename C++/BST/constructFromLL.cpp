#include"constructTreeFromInorder.cpp"
using namespace std;

// count n by using temp variable
Node* constructFromLL(Node* head,int n){
    if(!head||n<=0) return NULL;
    Node* leftTree = constructFromLL(head,n-1-n/2);
    Node* root = new Node(head->val);
    root->left = leftTree;
    head = head->next;
    root->right = constructFromLL(head,n/2);
    return root;
}

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node * next;
    
    Node(int val){
        this->val = val;
        next = NULL;
    }
};

void displayNode(Node * head){
    if(head == NULL) return ;
    cout<<head->val<<endl;
    displayNode(head->next);
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(11);
    Node* f = new Node(21);
    Node* g = new Node(31);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;

    displayNode(a);
    return 0;
}
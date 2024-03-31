#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int val){
        this->val= val;
        next = NULL;
    }
};

int main(){

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;

    cout<<a->next->next->next->val;

    // Node* temp =a;
    // while(temp != NULL){
    //     cout<<temp->val<<"  ";
    //     temp = temp->next;
    // }

    return 0;
}
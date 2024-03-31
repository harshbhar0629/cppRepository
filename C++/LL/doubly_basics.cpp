#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int val ;
    Node* next;
    Node* prev;

    Node(int v): val(v), prev(NULL),next(NULL){}
};

void display(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void displayRev(Node* tail){
    Node* temp = tail;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}
// class DoublyLL{
// public:
//     Node* head;
   
// };

int main(){
    Node* a = new Node(18);
    Node* b = new Node(17);
    Node* c = new Node(16);
    Node* d = new Node(15);
    Node* e = new Node(14);
    Node* f = new Node(13);
    Node* g = new Node(12);
    Node* h = new Node(11);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->prev = g;
    g->prev = f;
    f->prev = e;
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    display(a); 
    displayRev(h);
    return 0;
}
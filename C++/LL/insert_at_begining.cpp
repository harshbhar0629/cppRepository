#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node* next;
    node(int val){
        this->val = val;
        next = NULL;
    }
};

class LL{
public:
    int size;
    node *head;
    node* tail;
    
    LL(){
        head= tail=NULL;
        size=0;
    }

    void insert_at_begin(int val){
        node * temp = new node(val);
        if(size == 0){
            head=tail=temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LL l;
    l.insert_at_begin(10);
    l.display();
    cout<<l.size<<endl;
    l.insert_at_begin(20);
    l.insert_at_begin(30);
    l.display();
    cout<<l.size<<endl;

    return 0;
}
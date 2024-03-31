#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node * next;
    Node(int val){
        this->val=val;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size=0;
    }

    void insertAtEnd(int val){
        Node* temp = new Node(val);

        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        } 
        size++;
    }

    void display(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->val<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList ll;
    ll.insertAtEnd(20);
    ll.display();
    cout<<"LL size : "<<ll.size<<endl;
    ll.insertAtEnd(70);
    ll.display();
    cout<<"LL size : "<<ll.size<<endl;
    ll.insertAtEnd(10);
    ll.insertAtEnd(30);
    ll.display();
    cout<<"LL size : "<<ll.size<<endl;
    return 0;
}
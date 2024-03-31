#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    Node* next;
    Node* prev;
    int val;
    Node(int val){
        this->val = val;
        prev =  next = NULL;
        NULL;
    }
};

class Deque{
    int size;
    Node* tail;
    Node* head;
public: 

    Deque(): size(0),tail(NULL),head(NULL) {}

    void push_front(int x){
        Node *temp = new Node(x);
        if(size==0){
            head = tail =temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void push_back(int x){
        Node* temp = new Node(x);
        if(size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void pop_front(){
        if(size==0){
            cout<<"Deque is empty !!Underflow!! \n";
        }
        else{
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
        }
    }

    void pop_back(){
        if(size==0){
            cout<<"Deque is empty !!Underflow!! \n";
        }
        else{
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            size--;
            delete temp;
        }
    }

    int front(){
        if(size==0){
            cout<<"Deque is empty !!Underflow!! ";
            return -1;
        }
        else{
            return head->val;
        }
    }

    int back(){
        if(size==0){
            cout<<"Deque is empty !!Underflow!! ";
            return -1;
        }
        else{
            return tail->val;
        }
    }

    int size_deque(){
        return size;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<"  ";
            temp = temp->next;
        }cout<<endl;
    }


};


int main(){

    Deque dq;
    dq.pop_back();
    dq.pop_front();
    cout<<dq.back()<<"\n";
    cout<<dq.front()<<"\n";
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(0);
    dq.display();
    cout<<"size : "<<dq.size_deque()<<endl;
    dq.pop_back();
    cout<<"pop back : \n";
    dq.display();
    cout<<"size : "<<dq.size_deque()<<endl;
    dq.pop_front();
    cout<<"pop front : \n";
    dq.display();
    cout<<"size : "<<dq.size_deque()<<endl;

    return 0;
}
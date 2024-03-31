#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int val;
    Node* next;

    Node(int v): val(v),next(NULL) {}
};

class Queue{
    Node *head;
    Node* tail;
    int size;

public:
    // inline constructor
    Queue(){
        size=0;
        head = tail = NULL;
    }

    void push(int x){
        Node* temp = new Node(x);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void pop(){
        if(size==0){
            cout<<"Queue is empty !!Underflow!! \n";
        }
        else{
            Node *temp = head;
            head = head->next;
            size--;
            delete(temp);
        }
    }

    int front(){
        if(size==0){
            cout<<"Queue is empty !!Underflow!! ";
            return -1;
        }
        else{
            return head->val;
        }
    }

    int back(){
        if(size==0){
            cout<<"Queue is empty !!underflow!! ";
            return -1;
        }
        else {
            return tail->val;
        }
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<"  ";
            temp = temp->next;
        }cout<<endl;
    }

    int size_Q(){
        return size;
    }

};

int main(){

    Queue qu;
    int k=1;
    cout<<qu.front()<<"\n";
    cout<<qu.back()<<"\n";
    qu.pop();
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.display();
    cout<<"Queue size: "<<qu.size_Q()<<"\n";
    cout<<"pop -> : \n";
    qu.pop();
    qu.display();
    cout<<"Queue back: "<<qu.back();
    cout<<"Queue size: "<<qu.size_Q()<<"\n";



    return 0;
}
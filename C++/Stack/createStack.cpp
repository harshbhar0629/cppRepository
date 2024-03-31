#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next ;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

class Stack{
public:
    Node* head;
    int size;

    Stack(){
        head = NULL;
        size =0;
    }

    void push(int val){
        Node * temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop(){
        if(head==NULL){
            cout<<"stack is empty!!"<<endl;
            return;
        }
        else{
            size--;
            head = head->next;
        }
    }

    int top(){
        if(head == NULL){
            cout<<"Stack is empty!!"<<endl;
            return -1;
        }
        else{
            return head->val;
        }
    }

    void print(Node* t){
        if(t==NULL) return;
        print(t->next);
        cout<<t->val<<"  ";
    }

    void display(){
        Node* t = head;
        print(t);
        cout<<endl;
    }
};

int main(){

    int k=1;
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);
    st.push(90);
    st.display();
    st.pop();
    st.display();

    return 0;
}
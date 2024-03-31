#include <bits/stdc++.h>
using namespace std;

class node{
public:
    node* next;
    int val;
    node(int v){
        val = v;
        next = NULL;
    }
};

class LL{
public:
    node* head;
    node* tail;
    int size;
    LL(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtHead(int val){

        node* temp = new node(val);
        if(size==0){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;    
        }
        cout<<"insertion done\n";
        size++;
    }
    void insertAtTail(int val){

        node* temp = new node(val);
        if(size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;    
        }
        cout<<"insertion done\n";
        size++;
    }
    void insertAtIdx(int val, int idx){

        node* t = new node(val);
        if(idx==0){
            insertAtHead(val);
        }
        else if(idx==size){
            insertAtTail(val);    
        }
        else{
            node* temp = head;
            for(int i=0; i<idx-1; i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            cout<<"insertion Done\n";
            size++;
        }
        cout<<"insertion done\n";
        size++;
    }

    void display(){
        node* t= head;
        cout<<"Display: ";
        while(t){
            cout<<t->val<<" ";
            t = t->next;
        }cout<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    LL obj1;
    while(t--){
        cout<<"\n\n";
        cout<<"1 insert at head\n";
        cout<<"2 insert at tail\n";
        cout<<"3 insert at idx\n";
        int x;
        cin>>x;
        if(x<1 || x>3)
        if(x==1){
            cout<<"Enter val: ";
            int val;
            cin>>val;
            obj1.insertAtHead(val);
        }
        if(x==2){
            cout<<"Enter val: ";
            int val;
            cin>>val;
            obj1.insertAtTail(val);
        }
        
        if(x==3){
            cout<<"Enter val and idx: ";
            int val,idx;
            cin>>val>>idx;
            obj1.insertAtIdx(val,idx);
        }
        obj1.display();
    }

    return 0;
}
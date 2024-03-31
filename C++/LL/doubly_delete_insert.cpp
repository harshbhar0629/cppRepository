#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int val ;
    Node* next;
    Node* prev;

    Node(int v): val(v), prev(NULL),next(NULL){}
};

class DLL{
public:
    Node* head;
    Node* tail ;
    int size;
    DLL(){
        head = tail =NULL;
        size =0;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0){
            head = tail= temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size == 0){
            head = tail=temp;
        }        
        else{
            head->prev = temp;
            temp->next  = head;
            head = temp;
        }
        size++;
    }

    void InsertAtIdx(int val , int idx){
        if(idx<0 || idx>size) cout<<"invalid index!!"<<endl;
        else if(size-1 == idx)  insertAtTail(val);
        else if(size==0)  insertAtHead(val);
        else{
            Node* temp = new Node(val);
            Node* t = head;
            for(int i =1;i<= idx -1;i++){
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
            temp->prev = t;
            temp->next->prev = temp;
            size++;
        }
 
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<"  ";
            temp = temp->next; 
        } cout<<endl;
    }

    void displayRev(){
        Node* temp = tail;
        while(temp){
            cout<<temp->val<<"  ";
            temp = temp->prev; 
        } cout<<endl;
    }
    void deleteHead(){
        if(size==0) cout<<"empty List"<<endl;
        else{
            head = head->next;
            if(head)
            head->prev = NULL;
            else{
                tail = NULL;
            }
            size--;
        }
    }

    void deleteTail(){
        if(size==0) cout<<"Listis emoty"<<endl;
        else if(size==1){
            size--;
            tail = head=NULL;
        }
        else{
            tail = tail->prev;
            tail->next = NULL;
            size--;
        }
    }

    void deleteAtIdx(int idx){
        if(idx<0 || idx>size) cout<<"invalid index!!"<<endl;
        else if(idx == size-1) deleteTail();
        else if(idx==0) deleteHead();
        else{
            Node* temp = head;
            for(int i=1;i<idx-1;i++) temp = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            size--;

        }
    }
};

int main(){
   DLL *l = new DLL() ;
    l->insertAtHead(1);
    l->insertAtTail(2);    
    l->insertAtTail(3);    
    l->insertAtTail(4);
    l->insertAtTail(5);
    l->insertAtTail(6);
    l->insertAtTail(1);
    l->insertAtTail(2);    
    l->insertAtTail(3);    
    l->insertAtTail(4);
    l->insertAtTail(5);
    l->insertAtTail(6);
    l->display();
    // l->displayRev();
    // l->deleteHead();
    // l->display();
    // l->deleteTail();
    // l->display();
    // l->deleteHead();
    // l->display();
    // l->deleteTail();
    // l->display();
    l->deleteAtIdx(2);
    l->display();
    l->deleteAtIdx(5);
    l->display();
    return 0;
}
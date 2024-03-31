#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node*next;
    node(int val){
        this->val = val;
        next=NULL;
    }
};

class LL{
public:
    node*head;
    node*tail;
    int size;

    LL(){
        head=tail=NULL;
        size=0;
    }

    void insert_at_head(int val){
        node* temp = new node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            temp->next = head;
            head= temp;
        }
        size++;
    }

    void insert_at_end(int val){
        node* temp=new node(val);

        if(size==0){
            tail=head=temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insert(int idx , int val){
        if(idx<0 || idx>size) cout<<"invalid position"<<endl;
        else if(idx == 0) insert_at_head(val);
        else if(idx == size) insert_at_end(val);
        else{
            node* temp=new node(val);
            node*t=head;

            for(int i=1;i<idx;i++){
                t=t->next;
            }

            temp->next = t->next;
            t->next = temp;
            size++;
        }
    }

    void deleteHead(){
        if(size==0) cout<<"list is empty!"<<endl;
        else{
            head = head->next;
            size--;
        }
    }

    void deleteTail(){
        if(size==0) cout<<"list is empty!"<<endl;
        else{
            size--;
            node* temp=head;
            while(temp->next != tail){
                temp = temp->next;
            }

            temp->next =NULL;
            tail=temp;
        }
    }

    void deleteAtIdx(int idx){
        if(idx<0 || idx>=size) cout<<"Invalid index!"<<endl;
        else if(idx==0) deleteHead();
        else if(idx == size-1) deleteTail();
        else{
            node * temp=head;
            for(int i=1;i<idx;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }

    void display(){
        node*t = head;
        while(t!=NULL){
            cout<<t->val<<"  ";
            t = t->next;
        }
        cout<<endl;
    }
};
int main(){

   
    // LL l1;
    // l1.insert_at_end(20);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    // l1.insert_at_end(30);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    // l1.insert_at_end(40);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    // l1.insert_at_head(10);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    // l1.insert(2,21);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    // l1.insert_at_end(50);
    // l1.insert_at_end(60);
    // cout<<"size is :"<<l1.size<<endl;
    // l1.deleteAtIdx(0);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    // l1.deleteAtIdx(6);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    // l1.deleteAtIdx(3);
    // l1.display();
    // cout<<"size is :"<<l1.size<<endl;
    
    return 0;
}
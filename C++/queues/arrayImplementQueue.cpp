#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int size;
    int front_idx;
    int emptyIdx;
public: 
   
    Queue(int size){
        arr = new int[size];
        this->size = size;
        front_idx =0 ;
        emptyIdx =0;
    }

    int front(){
        if(front_idx == size) {
            cout<<"!!Overflow!!"<<endl;
            return -1;
        }
        return arr[front_idx];
    }

    void pop(){
        if(front_idx==size){
            cout<<"!!Underflow!! \n";
        }
        else{
            front_idx++;
        }
    }

    void display(){
        for(int i=front_idx;i<size;i++){
            cout<<arr[i]<<"  ";
        }cout<<endl;
    }

    void push(int x){
        if(emptyIdx==size){
            cout<<"Queue size is full !!Overflow!!"<<endl;
        }
        else{
            arr[emptyIdx++] =x;
        }
    }

    int back(){
        if(emptyIdx==0){
            cout<<"Queue is empty !!Underflow!! ";
            return -1;
        }
        else{
            return arr[emptyIdx-1];
        }
    }

    int currSize(){
        return emptyIdx;
    }

    int sizeQ(){
        return size;
    }

    bool isEmpty(){
        if(emptyIdx==size) return 0;
        else return 1;
    }

};

int main(){
    int n;
    cout<<"Enter size of Queue: ";
    cin>>n;
    Queue qu(n);
    cout<<qu.back()<<"\n";
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.display();
    cout<<"Curr size of queue "<<qu.currSize()<<"\n";    
    cout<<"queue back: "<<qu.back();
    return 0;
}
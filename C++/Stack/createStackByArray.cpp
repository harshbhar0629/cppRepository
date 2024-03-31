#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int idx ;
    int *arr;
    int s;
    Stack(int size){
        idx = -1;
        this->s = size;
        arr = new int[size];
    }

    int size(){
        if(idx==-1) cout<<" stack is empty!!"<<endl;
        else return idx+1;
    }

    int top(){
        if(idx==-1)  cout<<"sorry stack have don't have any element !!"<<endl;
        else  return arr[idx];
    }

    void push(int val){
        if(idx>= s-1){
            cout<<"stack is full !!"<<endl;
            return;
        }
        idx++;
        arr[idx]  = val;
    }
    
    void pop(){
        if(idx!=-1) idx--;
        else cout<<"segmentation fault !!"<<endl;
    }

    void display(){
        for(int i=0;i<=idx ;i++){
            cout<<arr[i]<<"  ";
        }cout<<endl;
    }

};

int main(){

    Stack st(5);
    int k=1;
    st.push(k++);
    st.push(k++);
    st.push(k++);
    // st.display();
    // st.pop();
    st.display();
    st.push(k++);
    st.push(k++);
    cout<<st.top()<<endl;
    st.push(k++);
    st.push(k++);
    st.display();
    // st.pop();
    // st.display();
    cout<<st.top()<<endl;
    return 0;
}
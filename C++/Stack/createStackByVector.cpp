#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    vector<int>v;
    
    void push(int val){
        v.emplace_back(val);
    }

    void pop(){
        if(v.size()==0) cout<<"stack is empty !!"<<endl;
        else v.pop_back();
    }

    int top(){
        if(v.size()==0){
            cout<<"stack is empty!!"<<endl;
            return -1;
        }
        else return v.back();
    }

    int size(){
        return v.size();
    }

    void display(){
        for(int i=0 ;i<v.size();i++){
            cout<<v[i]<<"  ";
        }cout<<endl;
    }

};

int main(){

    int k=1;
    Stack st;
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.display();
    cout<<"pop"<<endl;
    st.pop();
    st.display();
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.display();
    
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& st,int x){
    if(st.size()==0){
        st.push(x);
        return;
    }
    int num = st.top();
    if(x<num) {
        st.pop();
        insert(st,x);
         st.push(num);
    }
    else st.push(x);
   
}

void sort(stack<int>&st){
    if(st.size()==0) return;
    int x = st.top();
    st.pop();
    sort(st);
    insert(st,x);
}

void display(stack<int>st){
    if(st.size() == 0 ) return;
    int x = st.top();
    st.pop();
    display(st);
    cout<<x<<"  ";
}

int main(){
    stack<int>st;
    st.push(9);
    st.push(7);
    st.push(5);
    st.push(-2);
    st.push(1);
    st.push(-1);
    st.push(2);
    st.push(4);
    st.push(3);
    display(st);
    cout<<endl;
    sort(st);
    display(st);
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &st,int n,int count){
    if(count == n/2){
        st.pop();
        return;
    }
    int x = st.top();
    st.pop();
    deleteMid(st,n,++count);
    st.push(x);
    
}

void display(stack<int>st){
    while(st.size()>0){
        cout<<st.top()<<"  ";
        st.pop();
    }cout<<endl;
}

int main(){
    stack<int>st;
    int k =1;
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.push(k++);
    st.push(k++);
    // display(st);
    deleteMid(st,9,0);
    display(st);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int>& st,int val){
    if(st.size()==0) {
        st.push(val);
        return ;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}

void reverse(stack<int> &st){
    if(st.size()==1) return;
    int x = st.top();
    st.pop();
    reverse(st);
    pushAtBottom(st,x);
}

void display(stack<int>st){
    if(st.size()<=0) return;
    int x = st.top();
    st.pop(); 
    display(st);
    st.emplace(x);
    cout<<x<<"  ";
}

int main(){
    stack<int>st;
    int k=1;
    st.emplace(k++);
    st.emplace(k++);
    st.emplace(k++);
    st.emplace(k++);
    st.emplace(k++);
    st.emplace(k++);
    st.emplace(k++);
    st.emplace(k++); 
    display(st);
    cout<<endl;
    reverse(st);
    display(st);

    return 0;
}
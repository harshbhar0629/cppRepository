#include<bits/stdc++.h>
using namespace std;

void displayRev(stack<int>st){
    if(st.size()<=0) return;
    int x = st.top();
    st.pop(); 
    displayRev(st);
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
    displayRev(st);

    return 0;
}
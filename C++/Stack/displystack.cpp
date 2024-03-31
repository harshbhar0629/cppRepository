#include<bits/stdc++.h>
using namespace std;

// void display(stack<int>&st,bool flag ){
//     st.pop();

//     cout<<st.top()<<" ";
// }

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
  
    cout<<st.size();
    return 0;
}
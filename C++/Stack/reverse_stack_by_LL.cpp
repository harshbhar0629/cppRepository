#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val ;
    Node* next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};

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
    
    Node* dummy = new Node(2);
    Node* temp = dummy;

    // assigning the value of stack to LL
    while(st.size()>0){
        temp->next = new Node(st.top());
        temp = temp->next;
        cout<<st.top()<<"  ";
        st.pop();
    }cout<<endl;       

    // LL will become 8  7  6  5  4  3  2  1  
    dummy = dummy->next;
    temp = dummy;

    // now put into stack then stack will become reverse 1  2  3  4  5  6  7  8 
    while(temp){
        st.push(temp->val);
        temp = temp->next;
    }

    // while(st.size()>0){
        
    //     cout<<st.top()<<"  ";
    //     st.pop();
    // }cout<<endl;

    return 0;
}
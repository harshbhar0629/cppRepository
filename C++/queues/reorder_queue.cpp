#include <bits/stdc++.h>
using namespace std;
int main(){
    // in reorder of queue size is always even 
    // queue is : 1 2 3 4 5 6 7 8 
    // step1 now create a stack
    // step2 starting half element push in stack it will give me in reverse order
    // after putting stack have element 4 3 2 1 and queue 5 6 7 8
    // step3 simply pushed stack element in queue: 5 6 7 8 4 3 2 1 
    // step4 again half element of queue pushed in stack 8 7 6 5 and queue 4 3 2 1
    // step5  push queue front into its back and after push stack top ele
    // queue will be 4 8 3 7 2 6 1 5 
    // step6 push all element in stack then it will give a required o/p
    
    
    
    queue<int> qu;
    int k = 1;
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    int n = qu.size()/2;
    
    // step1
    stack<int>st;

    // step2
    for(int i=0;i<n;i++){
        st.push(qu.front());
        qu.pop();
    }

    // step3
    for(int i=0;i<n;i++){
        qu.push(st.top());
        st.pop();
    }

    // step4
    for(int i=0;i<n;i++){
        st.push(qu.front());
        qu.pop();
    }

    // step5
    for(int i=0;i<n;i++){
        qu.push(st.top());
        st.pop();
        qu.push(qu.front());
        qu.pop();
    }

    // step6
    while(qu.size()>0){
        st.push(qu.front());
        qu.pop();
    }

    // step7 
    while(st.size()>0){
        qu.push(st.top());
        st.pop();
    }

    for(int i=0;i<2*n;i++){
        cout<<qu.front()<<"  ";
        qu.push(qu.front());
        qu.pop();
    }

    return 0;
}
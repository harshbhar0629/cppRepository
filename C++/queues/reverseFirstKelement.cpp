#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>& qu){
    if(qu.size()<=1) return;
    int x =qu.front();
    qu.pop();
    reverse(qu);
    qu.push(x);
}

int main(){
    queue<int>qu;
    int k=1;
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    for(int i=0;i<qu.size();i++){
        cout<<qu.front()<<"  ";
        qu.push(qu.front());
        qu.pop();
    }cout<<endl;
    
    reverse(qu);

    for(int i=0;i<qu.size();i++){
        cout<<qu.front()<<"  ";
        qu.push(qu.front());
        qu.pop();
    }cout<<endl;
    // int k,n;
    // queue<int>qu;
    // cout<<"enter element of queue: ";
    // cin>>n;
    // cout<<"enter K: ";
    // cin>>k;

    // cout<<"enter element of queue: ";
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     qu.push(x);
    // }
    // stack<int>st;
    
    // for(int i=0;i<k;i++){
    //     st.push(qu.front());
    //     qu.pop();
    // }

    // for(int i=0;i<k;i++){
    //     qu.push(st.top());
    //     st.pop();
    // }

    // for(int i=k;i<n;i++){
    //     qu.push(qu.front());
    //     qu.pop();
    // }

    // cout<<"reverse k element of queue: ";
    // for(int i=0;i<n;i++){
    //     cout<<qu.front()<<"  ";
    //     qu.push(qu.front());
    //     qu.pop();
    // }



    return 0;
}
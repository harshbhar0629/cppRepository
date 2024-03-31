#include<bits/stdc++.h>
using namespace std;

void display(stack<int>st){
    stack<int>temp;
    while(st.size()>0){
        temp.emplace(st.top());
       // cout<<st.top()<<"  ";
        st.pop();
    }

    while(temp.size()>0){
        st.emplace(temp.top());
       cout<<temp.top()<<"  ";
        temp.pop();
    }cout<<endl;
}

void push_ele_atIdx(stack<int>& st,int k , int ele){
    stack<int>temp;

    if(k<0 || k>st.size()) cout<<"invalid index !!"<<endl;
    else {
        if(k == 0) temp.emplace(ele);
        else{
            while(st.size()>0){
                temp.emplace(st.top());
                st.pop();
            }
            for(int i=0;i<k;i++){
                st.emplace(temp.top());
                temp.pop();
            }
            temp.emplace(ele);
            while(st.size()>0){
                temp.emplace(st.top());
                st.pop();
            }
            while(temp.size()>0){
                st.emplace(temp.top());
                temp.pop();
            }
        }
    }

}
void push_ele_smartly(stack<int>& st ,int k , int ele){
    stack<int>temp;
    if(k<0 || k>st.size()) cout<<"invalid index !!"<<endl;
    else {
        k = st.size()-k;
        for(int i=0;i<k;i++){
            temp.emplace(st.top());
            st.pop();
        }
        st.emplace(ele);
        while(temp.size()>0){
            st.emplace(temp.top());
            temp.pop();
        }
    }

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
    // stack willl become 8 7 6 5 4 3 2 1
    // size == 7 according to zero base indexing
    stack<int>temp;

    int ele;
    cout<<"enter index and element : ";
    cin>>k>>ele;
    push_ele_smartly(st,k,ele);
    
    display(st);



    return 0;
}
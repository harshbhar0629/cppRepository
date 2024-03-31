#include<bits/stdc++.h>
using namespace std;
int solve(int x,char ch,int y){
    if(ch=='-') return x-y;
    else if(ch=='+') return x+y;
    else if(ch=='*') return x*y;
    else return x/y;
}
int main(){
    string s="-/*+79483";
    stack<int>st;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='0' and s[i]<='9'){
            st.push(s[i]-'0');
        }
        else {
            int val1=st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            int ans=solve( val1 , s[i] ,val2);
            st.push(ans);   
        }
    }
    cout<<st.top();
    return 0;
}
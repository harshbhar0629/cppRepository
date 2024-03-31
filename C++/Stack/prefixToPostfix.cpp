#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="-/*+79483";
    // ans = 79+4*8/3-
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='0' and s[i]<='9'){
            st.push(to_string(s[i]-'0'));
        }
        else {
            string val1=st.top();
            st.pop();
            string val2 = st.top();
            st.pop();
            string ans= val1 +val2 +s[i];
            st.push(ans);   
        }
    }
    cout<<st.top();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="-/*+79483";
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
            string ans= val1 + s[i] +val2;
            st.push(ans);   
        }
    }
    cout<<st.top();
    return 0;
}
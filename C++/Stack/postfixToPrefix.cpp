#include<bits/stdc++.h>
using namespace std;
int main(){
    // 34+6*8/2- postfix
    // -/*+34682 prefix
    // 3+4*6/8-2

    stack<string> st;
    string s("79+4*8/3-");
    // ans = -/*+79483
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            st.emplace(to_string(s[i]-'0'));
        }
        else{
            string s2= st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            string ans = s[i] + s1 + s2;
            st.push(ans);
        }
    }
    cout<<st.top();


    return 0;
}       
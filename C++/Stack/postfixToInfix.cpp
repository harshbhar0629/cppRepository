#include<bits/stdc++.h>
using namespace std;
int main(){
    // 34+6*8/2- postfix
    // 3+4*6/8-2 infix

    stack<string> st;
    string s("794*8/+3-");
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            st.push(to_string(s[i]-'0'));
        }
        else{
            string s2= st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            string ans = s1 + s[i] + s2;
            st.push(ans);
        }
    }
    cout<<st.top()<<endl<<st.size();


    return 0;
}       
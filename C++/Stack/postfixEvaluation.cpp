#include<bits/stdc++.h>
using namespace std;
int solve(char ch,int x,int y){
    if(ch=='-') return x-y;
    else if(ch=='+') return x+y;
    else if(ch=='*') return x*y;
    else return x/y;
}
// postfix = val1 val2 operator
int main(){
    stack<int>st;
    string s="794*8/+3-";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            st.push(s[i]-'0');
        }
        else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            int ans = solve(s[i],val1,val2);
            st.push(ans);
        }
    }
    cout<<st.top()<<endl;
    return 0;
}
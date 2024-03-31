#include<bits/stdc++.h>
using namespace std;

int prior_op(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}

int main(){
    string s = "7+9*4/8-3";// infix
    // ans-> postfix ->> (-+3/*4682)
    stack<char> op;
    stack<string> st;
    for(int i=0; i<s.size(); i++)  {
        if(s[i]>='0' and s[i]<='9'){
            st.push(to_string(s[i]-'0')); 
        }
        else{
            if(op.size()==0) op.push(s[i]);
            else if(s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.size()>0 and op.top()!='('){
                    string val2 = st.top();
                    st.pop();
                    string val1 = st.top();
                    st.pop();
                    char ch = op.top();
                    op.pop();
                    string ans = val1 +val2+ch;
                    st.push(ans);
                }
                op.pop();
            }
            else if(prior_op(s[i]) > prior_op(op.top())) op.push(s[i]);
            else{
                while(op.size()>0 and prior_op(s[i]) <= prior_op(op.top())){
                    string val2 = st.top();
                    st.pop();
                    string val1 = st.top();
                    st.pop();
                    char ch = op.top();
                    op.pop();
                    string ans =  val1 +val2 + ch;
                    st.push(ans);
                }
                op.push(s[i]);
            }
        }
    }  
    while(op.size()>0 ){
        string val2 = st.top();
        st.pop();
        string val1 = st.top();
        st.pop();
        char ch = op.top();
        op.pop();
        string ans = val1 + val2+ch;
        st.push(ans);
    }
    cout<<st.top();
    return 0;
}

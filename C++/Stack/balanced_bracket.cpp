#include<bits/stdc++.h>
using namespace std;

bool isBalancedBracket(string s){
    stack<char>st;
    if(s.size()%2!=0) return false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.emplace(s[i]);
        }
        else{
            if(st.size()==0) return false;
            else st.pop();
        }
    }
    if(st.size()==0) return true;
    else return false;
}

int main(){
    string s;
    cin>>s;

    if(isBalancedBracket(s)) cout<<"bracket are balanced ";
    else cout<<"not balanced";

    return 0;
}
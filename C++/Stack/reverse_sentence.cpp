#include<bits/stdc++.h>
using namespace std;

void reverseSentence(string s){
    stack<string>st;
    for(int i=0;i<s.size();i++){
        string word("");
        while(s[i]!=' ' and i<s.size()){
            word += s[i];
            i++;
        }
        if(word!="")
        st.push(word);
    }

    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl; 
}

int main(){
    string s="how are   you buddy?";
    reverseSentence(s);

    return 0;   
}
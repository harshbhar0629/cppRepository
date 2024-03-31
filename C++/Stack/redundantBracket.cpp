#include<bits/stdc++.h>
using namespace std;

bool redundant(string s){
    stack<int>st;

    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch == '(' || ch == '*' || ch == '+' || ch=='-' || ch=='/')
        {
            st.emplace(ch);
        }
        else
        {
            // if else so it is a close bracket or englist character
            if(ch == ')')
            {
                bool isredundant = true;
                while(st.top()!= '(')
                {
                    char top = st.top();
                    if(top == '*' || top == '+' || top=='-' || top=='/')
                    {
                        isredundant = false;
                    }
                    st.pop();
                }
                if(isredundant) return true;
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    // redunatant if he have extra brackets like ((a+b)) not redundant (a+b)
    // if an expression contain only one bracket between operator so it is not redundant 
    // if it contain extra bracket then redundant 
    string s("(a+b)-(a/b)");//not redundant bcoz don't have extra bracket
    
    if(redundant(s)){
        cout<<"Expression must contain extra bracket!!"<<endl;
    }
    else {
        cout<<"Expression don't contain extra bracket!!"<<endl;
    }
   

    return 0;
}
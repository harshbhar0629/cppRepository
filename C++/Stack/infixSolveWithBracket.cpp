#include<bits/stdc++.h>
using namespace std;

int prior_op(char ch){
    if(ch == '*' || ch=='/') return 2;
    else return 1;
}

int evaluate(int x ,char ch,int y){
    if(ch=='+') return x+y;
    else if(ch=='-') return x-y;
    else if(ch=='*') return x*y;
    else return x/y;
}

int main(){
    string s = "(2+3)*(4/(2+3))-1";
    stack<char>op;
    stack<int>val;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            val.push(s[i]-'0');
        }
        else{
            if(op.size()==0 ){
                op.push(s[i]);
            }
            else if(s[i]=='('){
                op.push(s[i]);
            }
            else if(op.top()=='('){
                op.push(s[i]);
            }
            else if(s[i]==')'){
                while( op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = evaluate(val1,ch,val2);
                    val.push(ans);
                }
                op.pop();

            }
            else if(prior_op(s[i]) >  prior_op(op.top())){
                op.push(s[i]);
            }
            else{
                while(op.size()>0 and prior_op(s[i]) <= prior_op(op.top())){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = evaluate(val1,ch,val2);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    cout<<"size"<<op.size()<<endl;

    while(op.size()>0  ){
        if(op.top()=='(') op.pop();
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = evaluate(val1,ch,val2);
        val.push(ans);
    }
    cout<<val.top()<<endl<<(2+3)*(4/(2+3))-1;

    return 0;
}
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
    string s = "2*2*2*3-2-2-1-3+4+5+5/5";
    stack<char>op;
    stack<int>val;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            val.push(s[i]-'0');
        }
        else{
            if(op.size()==0){
                op.push(s[i]);
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
                    cout<<val.top()<<endl;
                }
                op.push(s[i]);
            }
        }
    }

    while(op.size()>0 ){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = evaluate(val1,ch,val2);
        val.push(ans);
    }
    cout<<val.top();

    return 0;
}
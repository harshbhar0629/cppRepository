#include<bits/stdc++.h>
using namespace std;

void f(string s,int n,int open,int close){
    if(open==n && close==n){
        cout<<s<<endl;
        return;
    }
    if(open>n || close>n){
        return;
    }
        f(s+'(',n,open+1,close);
    if(close<open){
        f(s+')',n,open,close+1);

    }

 
}
int main(){
    int n=4;
    f("",n,0,0);
}
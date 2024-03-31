#include<bits/stdc++.h>
using namespace std;
void f(int n,char A,char H,char D){
    if(n==0){
        return ;
    }
    f(n-1,A,D,H);
    cout<<A<<" to "<<D<<endl;   
    f(n-1,H,A,D);
    // cout<<A<<" to "<<D<<endl;
   
}

int main(){
    int n;
    cin>>n;
    f(n,'S','H','D');
}
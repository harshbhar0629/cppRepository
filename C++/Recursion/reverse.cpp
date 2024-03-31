#include<iostream>
using namespace std;
 
 void f(int n,int &ans){
    if(n==0) return;
    ans=ans*10+n%10;
    f(n/10,ans);
}
int main(){
    int n;
    cin>>n;
    int ans=0;
    f(n,ans);
    cout<<ans;
}
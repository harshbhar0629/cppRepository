#include<bits/stdc++.h>
using namespace std;
int setbits(int n){
    n= n | (n>>1);
    n= n | (n>>2);
    n= n | (n>>4);
    n= n | (n>>8);
    n= n | (n>>16);
    return n;
}
int main(){
    int n;
    cin>>n;
    // int temp=setbits(n);
    int a= n ^ setbits(n);
    cout<<a;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int f(int a,int b){
    if(b==1) return a;
    if(b%2==0){
        int result=f(a,b/2);
        return result*result;
    }
    else{
        int p=f(a,(b-1)/2);
        return a*p*p;
    }
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    cout<<f(n,m);
}
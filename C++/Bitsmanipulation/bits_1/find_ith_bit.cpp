#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cout<<"enter number";
    cin>>n;
    int i;
    cout<<"enter ith bit";
    cin>>i;
    int n2 = (1<<i-1) & n;
    if(n2==0){
        cout<<"bit is 0";
    }
    else{
        cout<<"bit is 1";
    }
    return 0;
}
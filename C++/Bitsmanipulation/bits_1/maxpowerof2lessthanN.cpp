#include<bits/stdc++.h>
using namespace std;
int max_power_of2(int n){
    while(n){
        if((n & (n-1))==0){
          break;
        }
        else{
            n=(n & (n-1));
        }
    }
    return n;
}
int main(){
    int n;
    cin>>n;
    cout<<max_power_of2(n);
}
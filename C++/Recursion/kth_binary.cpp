#include<bits/stdc++.h>
using namespace std;

bool f(int n,int k){
   if(n==1) return 0;
   if(k%2==0){
    // int a=f(n-1,k/2);
    return !(f(n-1,k/2));
   }
   else{
        return f(n-1,k/2+1);
   }

 
}
int main(){
    int n=4,k=4;
    cout<<f(n,k);
}
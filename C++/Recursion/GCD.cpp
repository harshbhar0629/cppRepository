#include<bits/stdc++.h>
using namespace std;
// log(a+b)
int f(int a,int b){
    if(b==0) return a;
    if(b>a) f(b,a);
    return f(b,a%b);
}
int main(){
   int a,b;
   cin>>a>>b;
   cout<<f(a,b);
}
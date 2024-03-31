#include<bits/stdc++.h>
using namespace std;
int f(int a,int b,int &sum){
    if(a>b) return 0;
    if(a%2!=0) {
        sum+=a;
        f(a+2,b,sum);
    }
    else{
        f(a+1,b,sum);
    }
    return sum;
}

int main(){
    int n,m;
    cin>>n>>m;
    int sum=0;
    cout<<f(n,m,sum);
}
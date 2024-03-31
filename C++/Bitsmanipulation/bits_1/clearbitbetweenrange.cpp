#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=127;
    // cout<<"enter number:";
    // cin>>n;
    int i=2,j=5;
    // cout<<"enter range:";
    // cin>>i>>j;
    int n1= (1<<j);
    n1--;
    n1=~n1;
    int n2=(1<<i-1);
    n2--;
    n1=(n1|n2);
    int k= (n & n1);
    cout<<k<<endl;
    // add aanother number..
    int m=2;
    m= (m<<i-1);
    cout<<(m|k);
    return 0;
}
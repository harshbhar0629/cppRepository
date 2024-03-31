#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i;
    cin>>i;
    int n2= ~(1<<i-1);
    cout<<(n2 & n);
    return 0;
}
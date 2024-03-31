#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n, s=0;
    cin>>n;
    // vector<bool>vis(n, 0);
    // vector<ll>v(n-1);
    for(int i=0; i<n-1; i++){

        int a;
        cin>>a;
        s+=a;
    }

    cout<<n*(n+1)/2 - s<<"\n";


    return 0;
}
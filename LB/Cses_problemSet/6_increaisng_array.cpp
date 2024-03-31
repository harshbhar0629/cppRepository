#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    int n;
    cin>>n;

    ll a = 0;
    int maxi = 0;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        maxi = max(maxi, x);
        a+=maxi-x;
    }

    cout<<a<<endl;

}
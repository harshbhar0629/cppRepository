#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void f(ll n){
    cout<<n<<" ";
    while(n!=1){
        if(n&1){
            n = n*3 + 1;
        }
        else{
            n/=2;
        }
        cout<<n<<" ";
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;

    f(n);


    return 0;
}
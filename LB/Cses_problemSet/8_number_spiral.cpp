#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    int t;
    cin>>t;

    while(t--){
        ll x, y;
        cin>>x>>y;
        ll z = max(x,y), ans;
        ll z2 = (z-1)*(z-1);

        if(z&1){
            if(z==y){
                ans = z2 + z*2 - x;
            }
            else{
                ans = z2+y;
            }
        }
        else{
            if(y==z){
                ans = z2 + x;
            }
            else{
                ans = z2 + z*2 -y;
            }
        }
        cout<<ans<<endl;
    }

}

#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define dd double
#define ll long long int
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vl vector<ll>
#define MI INT_MIN
#define MX INT_MAX
#define vvl vector<vl>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lop(i,b) for(int i=0; i<b; i++)
#define rloop(i,a) for(int i=a; i>=0; i--)
#define res(i,a,b) for(int i=a; i>=b; i--)
#define N 1e9+7
#define mod N
#define pi pair<int,int>
#define vpi vector<pi>
#define ppi pair<int,pi>
#define pl pair<ll,ll>
#define ppl pair<ll,pl>
#define ri(vi) reverse(v.begin(),v.end())
#define rl(vl) reverse(v.begin(),v.end())
#define ff first
#define ss second
#define pb(x) push_back(x)
#define ppb pop_back()
#define tot(a) accumulate(a.begin(),a.end())
#define minELe(v) *min_element(v.begin(),v.end())

void solve(){
    ll a,m,l,r;
    cin>>a>>m>>l>>r;
    if(l<=a and a<=r){
        ll d1 = r-a;
        ll d2 = a-l;
        ll res = d1/m + d2/m+1;
        cout<<res<<endl; 
    }
    else if(a<=l){
        ll d = r-l;
        ll res = d/m+1;
        cout<<res<<endl;
    }
    else{
        ll d = r-l;
        ll res = d/m+1;
        cout<<res<<endl;
    }


}

int main(){

    ios_base::sync_with_stdio(true);
    cout.tie(0);
    cin.tie(0);

    int t=1;
    // cin>>t;

    while(t--){
        solve();

    }


    return 0;
}
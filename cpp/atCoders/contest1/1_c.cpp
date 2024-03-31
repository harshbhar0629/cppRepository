// https://atcoder.jp/contests/abc333/tasks/abc333_c
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
    
    vector<ll>v;
    ll p =1;
    v.pb(p);
    lop(i,12){
        p = p*10 + 1;
        // cout<<p<<" ";
        v.pb(p);
    }
    // cout<<endl;
    set<ll>s;
    lop(i,v.size()){
        lop(j, v.size()){
            lop(k, v.size()){
                s.insert(v[i]+v[j]+v[k]);
                // if(i==1 || i==2)
                // cout<<v[i]+v[j]+v[k]<< endl;
            }
        }
    }
    int n;
    cin>>n;
    // cout<<endl;
    lop(i, n-1){
        s.erase(s.begin());
    }
    cout<<*s.begin()<<endl;

}

int main(){

    ios_base::sync_with_stdio(true);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}
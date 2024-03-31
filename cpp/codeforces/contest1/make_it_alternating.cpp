// https://codeforces.com/contest/1879/problem/C
#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

#define ld long double
#define dd double
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define MI INT_MIN
#define MX INT_MAX
#define vvl vector<vl>
#define loop(i,a,b) for(int i=a; i<b; i++)
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
#define pop pop_back()
#define tot(a) accumulate(a.begin(),a.end())
#define minELe(v) *min_element(v.begin(),v.end())

ll M=998244353;

ll fact(int n){
    if(n<=1) return 1;
    return (n*(fact(n-1)%M))%M;
}

void solve(){
   
    string s;
    cin>>s;

    int n = s.size();
    int x =1;
    ll ans=1,cnt=1;
    
    loop(i,1,n){
        if(s[i-1]!=s[i]){
            (ans*=cnt) %= M;
            cnt=1;
            x++;
        }else{
            cnt++;
        }
    } 

    (ans*=cnt)%=M;

    (ans *= fact(n-x))%=M;

    cout<<(n-x)<<"  "<<ans<<endl;

}

int main(){

    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        solve();

    }


    return 0;
}
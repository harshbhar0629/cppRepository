// https://atcoder.jp/contests/abc333/tasks/abc333_d
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

vvi graph;

int dfs(int u, int p){
    int res = 1;
    for(auto& v: graph[u]){
        if(v!=p){
            res += dfs(v,u);
        }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    graph.resize(n);

    lop(i,n-1){
        int u,v;
        cin>>v>>u;
        u--,v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
// cout<<endl;
//     for(auto &x: graph){
//         for(auto u: x){
//             cout<<u+1<<" ";
//         }
//         cout<<endl;
//     }

    int mini = INT_MAX;

    for(auto& it: graph[0]){
        mini = min (mini, n - dfs(it, 0));
    }
    // int ans = n - mini;
    cout<<mini<<" ";
}

int main(){

    // ios_base::sync_with_stdio(true);
    // cout.tie(0);
    // cin.tie(0);

    solve();

    return 0;
}
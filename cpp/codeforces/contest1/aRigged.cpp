// https://codeforces.com/problemset/problem/1879/A
#include <iostream>
#include <vector>
#include <ctime>
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

void solve(){
    
    int n;
    cin>>n;
    vpi v(n);
    loop(i,0,n){
        cin>>v[i].first>>v[i].second;
    }

    loop(i,1,n){
        if(v[0].first<=v[i].first and v[0].second<=v[i].second){
            cout<<"-1\n";
            return;
        }
    }
    cout<<v[0].first<<"\n";

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
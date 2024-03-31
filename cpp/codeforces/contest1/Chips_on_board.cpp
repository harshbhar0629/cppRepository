// https://codeforces.com/contest/1879/problem/B
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
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

void solve(){
    int n;
    cin>>n;
    vl a(n),b(n);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];

    // we want one chips and int a row or column must have one chip
    ll ans1 = *min_element(b.begin(),b.end())*n + accumulate(a.begin(),a.end(),0ll);
    ll ans2 = *min_element(a.begin(),a.end())*n + accumulate(b.begin(),b.end(),0ll);

    cout<<min(ans1,ans2)<<endl;

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
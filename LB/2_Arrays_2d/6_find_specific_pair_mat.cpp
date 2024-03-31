#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <set>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include<bits/stdc++.h>
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

/**
 * brute force is a->0,n-1 and b->0,n-1 and c->a+1,n and d->b+1,n
*/

int maxDiff(vvi& mat, int n){
    vvi v(n,vi(n));
    v[n-1][n-1] = mat[n-1][n-1];
  
    // fill last row
    rloop(j,n-2){
        v[n-1][j] = max(v[n-1][j+1], mat[n-1][j]);
    }

    // fill last col
    rloop(j,n-2){
        v[j][n-1] = max(v[j+1][n-1], mat[j][n-1]);
    }

    // fill mat;

    rloop(i, n-2){
        rloop(j, n-2){
            v[i][j] = max({v[i+1][j] , v[i][j+1], mat[i][j]});
        }
    }

    // find max value;
    int ans = MI;

    loop(i, 0, n-1){
        loop(j, 0, n-1){
            int diff = v[i+1][j+1] - mat[i][j];
            ans = max(ans, diff);
        }
    }

    return ans;
}


void solve(){
    int n;
    cin>>n;
    vvi mat(n,vi(n));
    loop(i,0,n){
        lop(j,n){
            cin>>mat[i][j];
        }
    }
    

    cout<< maxDiff(mat, n);

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
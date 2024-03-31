#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/problems/MAKE_IT_ONE

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
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;

    if(len%2 == 0){
        for(int i=l; i<=r; i+=2){
            cout << i + 1 << " " << i<<" ";
        }
    }
    else if(r%2 != 0){
        for (int i = l; i < r - 2; i += 2){
            cout << i + 1 << " " << i << " ";
        }
        cout << r - 1 << " " << r << " " << r - 2;
    }
    else{
        cout << "-1";
    }
    cout << "\n";
}

int main(){

    ios_base::sync_with_stdio(true);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        solve();

    }


    return 0;
}
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
#include <set>
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

// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-operations-to-collect-elements/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        set<int>mp;
        int moves=0;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            moves++;
            if(nums[i]<=k)
                mp.insert(nums[i]);
            if(mp.size()==k) return moves;
        }
       
        return 0;
        
    }
};

void solve(){
    int n;
    cin>>n;
    vi v(n);
    loop(i,0,n) cin>>v[i];
    

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
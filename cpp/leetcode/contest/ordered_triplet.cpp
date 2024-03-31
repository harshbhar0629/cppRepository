// https://leetcode.com/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-i
// 2.
// https://leetcode.com/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-ii/
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


long long maximumTripletValue(vector<int>& nums) {
    ll maxAns=0;
    int n = nums.size();
    for(int k=n-1; k>=0; k--){
        for(int j=k-1; j>=0; j--){
            int maxi = 0;
            for(int i=0; i<j; i++){
                maxi = max(nums[i]-nums[j],maxi);            
            }
            ll ans = (ll)(maxi*nums[k]);
            maxAns= max(ans,maxAns);
        }
    }
    return maxAns;
}


// 2 constraints are diff or tight
 long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    vector<int>diff(n,-1);
    int maxi = nums[0];
    
    for(int i=1;i<n-1;i++){
        int d = maxi - nums[i];
        if(d>0) diff[i] = d; 
        maxi = max(maxi,nums[i]);
    }
    
    vector<int>greater(n,-1);
    greater[n-1] = nums[n-1]; 
    maxi = nums[n-1];
    
    for(int i=n-2; i>=1; i--){
        maxi = max(maxi,nums[i]);
        greater[i] = maxi;
    }
    
    ll ans=0;
    for(int i=1;i<n-1;i++){
        if(diff[i]<0) continue;
        ll val = (ll)diff[i];
        ll pdt = (ll)greater[i+1];
        ans = max(ans,val*pdt);
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vi v(n);
    loop(i,0,n) cin>>v[i];
    cout<<maximumTripletValue(v);

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
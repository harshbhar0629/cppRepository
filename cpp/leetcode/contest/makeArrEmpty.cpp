// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-number-of-operations-to-make-array-empty/
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


int minOperations(vector<int>& nums) {
    int n = nums.size();
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    int opn=0;
    for(auto it: mp){
        int val = it.second;
        if(val%3!=0 and val%2!=0) return -1;
        int a = 1e7;
        int b = 1e7;
        if(val%3==0){
            a = val/3;
        }
        if(val%2==0){
            b = val/2;
        }
        opn+=min(a,b);
    }
    return opn;
}

class Solution {
public:
    int minOperations1(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        
        int ans=0;
        for(auto it: mp){
            int val = it.second;
            if(val==1) return -1;
            if(val%3==0){
                int di = val/3;
                ans+=di;
            }
            if(val%3==1){
                int div = (val-4)/3 ;
                ans+=div+2;
            }
            if(val%3==2){
                int div =(val-2)/3+1;
                ans+=div;
            }
        }
        return ans;
    }
};

void solve(){
    int n;
    cin>>n;
    vi v(n);
    loop(i,0,n) cin>>v[i];
    
    cout<<minOperations(v);

}
// [14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12]

int main(){

    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);

    int t;
    cout<<"TestCase: ";
    cin>>t;

    while(t--){
        solve();

    }


    return 0;
}
// https://leetcode.com/problems/longest-mountain-in-array/
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


int f(vi& v){
    int n = v.size();
    vi dp1(n,1) , dp2(n,1);
    loop(i,0,n){
        loop(j,0,i){
            if(v[j]<v[i] and dp1[i] < dp1[j]+1){
                dp1[i] = 1+dp1[j];
            }
        }
    }

    rloop(i,n-1){
        res(j,n-1,i+1){
            if(v[j]<v[i] and dp2[i]<dp2[j]+1){
                dp2[i] = dp2[j]+1;
            }
        }
    }

    int maxi = MI;

    loop(i,0,n){
        maxi = max(dp1[i]+dp2[i]-1,maxi);
    }

    return n-maxi;
}


int longestMountain(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp1(n,1) , dp2(n,1);

    for(int i=1; i<n; i++){
        if(nums[i-1] < nums[i]){
            dp1[i] = dp1[i-1]+1;
        }
    }
    for(int i=n-2; i>=0; i--){
        if(nums[i+1] < nums[i]){
            dp2[i] = dp2[i+1]+1;
        }
    }

    int maxi = 0;
    for(int i=0; i<n; i++){
        if(dp1[i]>1 and dp2[i]>1){
            maxi = max(maxi , dp1[i] + dp2[i]-1);
        }
    }
    return maxi ;
}


int main(){

    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
    
    int n;
    vi v;
    loop(i,0,n){
        cin>>v[i];
    }

    cout<<f(v);

    return 0;
}
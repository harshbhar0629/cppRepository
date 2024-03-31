// https://atcoder.jp/contests/dp/tasks/dp_e
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long int
/// @brief 
/// @param v input vector value
/// @param tv target value 
/// @param w weight vector
/// @param i point to ith pos
/// @param f() this fun return min weight req to achieve this value
/// @return 


int f(vector<int>&v,vector<int>&w,int i,int tv){
    if(tv==0) return 0; //tv achieve ab kuch nahi chaiye
    if(i==v.size()) return 1e8;

    int ans = f(v,w,i+1,tv);
    
    if(v[i]<=tv){
        ans = min(ans,w[i]+f(v,w,i+1,tv-v[i]));
    }
    return ans;
}


vector<vector<ll>> dp;
int ftd(vector<int>&v,vector<int>&w,int i,int tv){
    if(tv==0) return 0; //tv achieve ab kuch nahi chaiye
    if(i==v.size()) return 1e8;
    if(dp[i][tv]!=-1) return dp[i][tv];

    int ans = ftd(v,w,i+1,tv);
    
    if(v[i]<=tv){
        ans = min(ans,w[i]+ftd(v,w,i+1,tv-v[i]));
    }
    return ans;
}


int fbu(vector<int>&v ,vector<int>&w,int W){
    
    dp.resize(105,vector<ll>(100005,INT_MAX));
    int n = v.size();
    int tv= n*1000;
    
    for(int i=0;i<dp.size();i++){
        dp[i][0] =0;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0; j<=tv; j++){
            ll ans = dp[i+1][j];
            if(v[i]<=j){
                ans = min(ans,dp[i+1][j-v[i]]+w[i]);
            }
            dp[i][j] = ans;
        }
    }

    int result=-1;
    for(int i=0;i<=tv;i++){
        if(dp[0][i]<=W){
            result = i;
        }
    }
    return result;
}


/**
 *  3 8
    3 30
    4 50
    5 60
->> 90

    6 15
    6 5
    5 6
    6 4
    6 6
    3 5
    7 2
->> 17
*/

int main(){
    int n;
    cin>>n;
    int W;
    cin>>W;

    vector<int>v(n);
    vector<int> w(n);

    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }

    
    // int ans =-1;
    // dp.resize(100,vector<ll>(100005,0));
    // for(int i=0; i<=n*1000; i++){
    //     if(ftd(v,w,0,i)<=W){
    //         ans = i;
    //     }
    // }
    // cout<<ans;

    cout<<fbu(v,w,W);

    return 0;
}
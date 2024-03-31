// https://www.spoj.com/problems/MIXTURES/
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int 
vector<ll>colors;
vector<vector<ll>>dp;

ll g(int m,int n){
    ll result=0;

    for(int i=m;i<=n;i++){
        result+=colors[i];
    }

    return result%100;
}


ll f(int i,int j){
    if(i==j) return 0;
    ll ans = 1e9;

    for(int k=i; k<j; k++){
        ans = min(ans,f(i,k)+f(k+1,j) + g(i,k)*g(k+1,j));
    }

    return ans;
}




ll ftd(int i,int j){
    if(i==j) return dp[i][j] =  0;
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans = 1e9;
    for(int k=i; k<j; k++){
        ans = min(ans,f(i,k)+f(k+1,j) + g(i,k)*g(k+1,j));
    }

    return dp[i][j] = ans;
}



ll fbu(){
    dp.resize(105,vector<ll>(105,0));
    int n = colors.size();

    for(int len=2; len<=n; len++){
        for(int i=0;i<=n-len; i++){

            int j = i+len-1;
            ll ans = 1e9;
            for(int k=i; k<j; k++){
                ans = min(ans,dp[i][k] +dp[k+1][j] + g(i,k)*g(k+1,j));
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}


/// @brief 
/// @param i and j denotes the length of color picked and it will produced smoke equal to color[i]*color[j] and its ans after smoke is color[i]+color[j]
/// @param color denotes the input color value color[0...99]
/// @param g funtion give the sum of the range 
/// @return 


int main(){
    
    int n;
    cin>>n;
    colors.resize(n);

    for(int i=0;i<n;i++){
        cin>>colors[i];
    }

    // cout<<f(0,n-1);

    // dp.resize(105,vector<ll>(105,-1));
    // cout<<ftd(0,n-1);

    cout<<fbu();

    return 0;
}
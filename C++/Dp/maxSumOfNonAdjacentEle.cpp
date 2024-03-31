#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int f(vector<int>&v,int i){
    if(i==v.size()-1) return v[v.size()-1];
    if(i>=v.size()) return INT_MIN;

    return max(v[i]+ f(v,i+2),0+f(v,i+1));
}

vector<int>dp;
int ftd(vector<int>&v,int i){
    if(i==v.size()-1) return v[v.size()-1];
    if(i>=v.size()) return INT_MIN;
    if(dp[i]!=-1) return dp[i];
    return dp[i] = max(v[i] + ftd(v,i+2),  0 + ftd(v,i+1));
}

int fbu(vector<int>&v){
    // int n = v.size();
    // dp.resize(n+3,0);
    // dp[n-1] = v[n-1];
    // for(int i=n-2;i>=0;i--){
    //     dp[i]= max(v[i]+dp[i+2] , dp[i+1]);
    // }
    int n = v.size();
    int prev1 = v[n-1];
    int prev2 = 0;
    for(int i=n-2;i>=0;i--){
        int sum = max(v[i]+prev2 , prev1);
        prev2 = prev1;
        prev1= sum;
    }

    return max(prev1,prev2);
}

int main(){
    
    int n ;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    // cout<<f(v,0);
    
    // dp.resize(n+2,-1);
    // cout<<ftd(v,0);

    cout<<fbu(v);

    return 0;
}
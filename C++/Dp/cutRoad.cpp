#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int f(vector<int>&v,int i,int n){

    if(n<=0 || i>=v.size()) return 0;
    int notTake = f(v,i+1,n);
    int take = INT_MIN;
    if(i+1<=n){
        take = v[i] + f(v,i,n-i-1);
    }
    return max(take,notTake);
}


vector<vector<int>>dp;
int ftd(vector<int>&v,int i,int rodLen){

    if(rodLen<=0 || i>=v.size()) return 0;
    if(dp[i][rodLen]!=-1) return dp[i][rodLen];
    int notTake = ftd(v,i+1,rodLen);
    int take = INT_MIN;
    if(i+1<=rodLen){
        take = v[i] + ftd(v,i,rodLen-i-1);
    }
    return dp[i][rodLen] = max(take,notTake);
}



int fbu(vector<int>&v,int rodLen){

    int n = v.size();
    dp.resize(n+5,vector<int>(rodLen+5,0));
    for(int i=n-1; i>=0 ;i--){
        for(int j=0; j<=rodLen; j++){
            int notTake = dp[i+1][j];
            int take = INT_MIN;
            if(i+1<=j){
                take = v[i] + dp[i][j-i-1];
            }
            dp[i][j] = max(take,notTake);
        }
    }
    return dp[0][rodLen];
}




int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int rodLen ;
    cin>>rodLen;

    // cout<<f(v,0,rodLen);

    dp.resize(n+5,vector<int>(rodLen+5,-1));
    cout<<ftd(v,0,rodLen);

    return 0;
}
// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?leftPanelTab=1
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(vector<int>&v,vector<int>wt,int weight,int i){
    if(i==0){
        if(wt[i]<=weight){
            return v[i];
        }
        return 0;
    }

    int inc = 0;
    if(wt[i] <= weight) inc = v[i] + f(v,wt,weight-wt[i],i-1);

    int exc = f(v,wt,weight,i-1);

    return max(inc,exc);
}


vector<vector<int>>dp;
int ftd(vector<int>&v,vector<int>wt,int weight,int i){
    if(i==0){
        if(wt[i]<=weight){
            return v[i];
        }
        return 0;
    }
    if(dp[i][weight]!=-1) return dp[i][weight];

    int inc = 0;
    if(wt[i] <= weight) inc = v[i] + f(v,wt,weight-wt[i],i-1);

    int exc = f(v,wt,weight,i-1);

    return dp[i][weight] = max(inc,exc);
}


int fbu(vector<int>&v,vector<int>wt,int weight){
    int n = v.size();
    dp.resize(n+1,vector<int>(weight+2,0));

    // base case
    for(int i= wt[0]; i<=weight; i++){
        if(wt[0] <= weight){
            dp[0][i] = v[0];
        }
        else dp[0][i] = 0;
    }

    // main portion
    for(int i=1; i<n; i++){
        for(int j=0; j<=weight; j++){
            int inc=0;
            if(wt[i]<=j){
                inc = v[i] + dp[i-1][j-wt[i]];
            }

            int exc = dp[i-1][j];
            dp[i][j] = max(inc,exc);
        }
    }
    return dp[n-1][weight];
}



int fbuOpt1(vector<int>&v,vector<int>wt,int weight){
    int n = v.size();
    vector<int>prev(weight+2,0), cur(weight+2,0);

    // base case
    for(int i= wt[0]; i<=weight; i++){
        if(wt[0] <= weight){
            prev[i] = v[0];
        }
        else prev[i] = 0;
    }

    // main portion
    for(int i=1; i<n; i++){
        for(int j=0; j<=weight; j++){
            int inc=0;
            if(wt[i]<=j){
                inc = v[i] + prev[j-wt[i]];
            }

            int exc = prev[j];
            cur[j] = max(inc,exc);
        }
        prev = cur;
    }

    return prev[weight];
}



int fbuOpt2(vector<int>&v,vector<int>wt,int weight){
    int n = v.size();
    vector<int> cur(weight+2,0);

    // base case
    for(int i= wt[0]; i<=weight; i++){
        if(wt[0] <= weight){
            cur[i] = v[0];
        }
        else cur[i] = 0;
    }

    // main portion
    for(int i=1; i<n; i++){
        for(int j=weight; j>=0; j--){
            int inc=0;
            if(wt[i]<=j){
                inc = v[i] + cur[j-wt[i]];
            }

            int exc = cur[j];
            cur[j] = max(inc,exc);
        }

    }
    
    return cur[weight];
}


int fbuDD(vector<int>&v,vector<int>&w,int W){
    dp.resize(105,vector<int>(100005,0));
    int n = v.size();
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=W;j++){
            int ans = dp[i+1][j];
            if(j>=w[i]) ans = max(ans,v[i] + dp[i+1][j-w[i]]);
            dp[i][j] = ans;
        }
    }
    return dp[0][W];
}


int main(){
    int n;
    cin>>n;
    vector<int>val(n);
    vector<int>w(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    
    int weight ;
    cin>>weight;

    // solution
    // cout<<f(val,w,weight,n-1);

    // dp.resize(n+2,vector<int>(weight+2,-1));
    // cout<<ftd(val,w,weight,n-1);

    // cout<<fbu(val,w,weight);

    // cout<<fbuOpt1(val,w,weight)<<endl;

    // cout<<fbuOpt2(val,w,weight);

    cout<<fbuDD(val,w,weight);
  
    return 0;
}
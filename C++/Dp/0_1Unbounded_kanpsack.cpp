// https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?leftPanelTab=0
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;


int dp[1005][1005];
int f(vector<int>&v,vector<int>&w,int W,int i){
    if(i>=v.size() || W<=0)  return 0;

    int notTake = f(v,w,W,i+1);
    int take = INT_MIN;
    
    if(w[i]<=W){
        take = v[i] + f(v,w,W-w[i],i);
    }
    return max(take,notTake);
}


int fb(vector<int>profit,vector<int>weight,int w){
    int n = profit.size();
    memset(dp,0,sizeof dp);
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=w; j++){
            int notTake  = dp[i+1][j];
            int take = INT_MIN;
            if(weight[i]<=j){
                take = profit[i] + dp[i][j-weight[i]];
            }
            dp[i][j] = max(take,notTake);
        }
    }
    return dp[0][w];
}


int fbu(vector<int>profit,vector<int>weight,int w){
    int n = profit.size();
    vector<int>curr(w+5,0),prev(w+5,0);
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=w; j++){
            int notTake  = prev[j];
            int take = INT_MIN;
            if(weight[i]<=j){
                take = profit[i] + curr[j-weight[i]];
            }
            curr[j] = max(take,notTake);
        }
        prev = curr;
    }
    return curr[w];
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>w(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>w[i];
    }

    int W;
    cin>>W;

    cout<<f(v,w,W,0);

    return 0;
}
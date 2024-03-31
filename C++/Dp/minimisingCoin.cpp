//https://cses.fi/problemset/task/1634 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(vector<int>&v,int target){
    if(target==0) return 0;
    if(target<0) return INT_MAX;

    int mini = INT_MAX;
    for(int i=0;i<v.size();i++){
        if(target-v[i]<0) continue;
        int a = f(v,target-v[i]);
        if(a!=INT_MAX){
            mini = min(mini,1+a);
        }
    }
    return mini;
}


vector<int>dp;
int ftd(vector<int>&v,int target){
    if(target==0) return 0;
    // if(target<=9) return 1;
    if(target<0) return INT_MAX;
    if(dp[target]!=-1) return dp[target];

    int mini = INT_MAX;
    for(int i=0;i<v.size();i++){
        if(target-v[i]<0) continue;
        mini = min(mini,ftd(v,target-v[i]));
    }
    if(mini==INT_MAX) return dp[target] = INT_MAX;
    return dp[target] = 1+ mini;
}


int main(){
    
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    dp.resize(target+2,-1);
    int ans = ftd(v,target);
    if(ans==INT_MAX) cout<<"-1\n";
    else cout<<ans;

    return 0;
}
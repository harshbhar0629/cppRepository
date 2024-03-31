// https://leetcode.com/problems/longest-increasing-subsequence/description/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int>dp;
int ftd(vector<int>& v,int i){
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];

    int maxi=INT_MIN;
    for(int j=0;j<i;j++){
        if(v[j]<v[i]){
            maxi = max(maxi,ftd(v,j));
        }
    }
    if(maxi==INT_MIN) return dp[i] = 1;
    return dp[i] = maxi+1;
}


int fbu(vector<int>&v){
    int n = v.size(); 
    dp.resize(n+2,-1);
    int ans = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
        if(dp[i]==-1) dp[i] = 1;
        ans = max(ans,dp[i]);
    }
    return ans;
}


int f(int v[],int n){
    vector<int>fp;
    int size=0;
    for(int i=0;i<n;i++){

        auto it = lower_bound(fp.begin(),fp.end(),v[i]);

        if(it!=fp.end()){
            cout<<*it<<" "<<i<<endl;
        }

        if(it==fp.end()) {
            cout<<i<<" "<<endl;
            fp.push_back(v[i]);
            size++;
        }
        else *it = v[i];
    }
    
    return size;
}


int printLIS(vector<int>&v){

    int n = v.size();
    vector<int>hash(n);
    int idx=0;
    vector<int>p(n+1,1);
    int maxi = 1;
    
    for(int i=0; i<n; i++){
        hash[i]=i;
        for(int j=0; j<i; j++){
            if(v[j]<v[i] and p[i]<p[j]+1){
                p[i] = 1+ p[j];
                hash[i] = j;
            }
        }
        if(maxi<p[i]){
            idx=i;
            maxi = p[i];
        }
    }

    vector<int> print;
    print.push_back(v[idx]);
    while(hash[idx]!=idx){
        idx = hash[idx];
        print.push_back(v[idx]);
    }

    reverse(print.begin(),print.end());

    for(auto it: print){
        cout<<it<<"  ";
    }cout<<endl;

    return maxi;
}


// 10,9,2,5,3,7,101,18
int main(){

    int n=8;
    // int v[] = {1,7,8,4,5,6,-1,9};
    vector<int>v={6,1,3,2,5,8};
    printLIS(v);

    // int ans = f(v,n);
    // cout<<ans;


    // cin>>n;
    // vector<int>v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }

    // int ans =-1;
    // dp.resize(n+2,-1);
    // for(int i=0;i<n;i++){
    //     ans = max(ans , ftd(v,i));
    // }
    // cout<<ans;

    // cout<<fbu(v);

    return 0;
}
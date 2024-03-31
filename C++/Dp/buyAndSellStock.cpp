#include <iostream>
#include <vector>
using namespace std;
#define for(i,a,b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>


int f(vi &v,int i,int k){
    if(i==v.size()) return 0;
    if(k){
        int c = f(v,i+1,k); 
        int d = f(v,i+1,0) + v[i];
        return max(c,d);
    }
    else{
        int a = f(v,i+1,k); 
        int b = f(v,i+1,1) - v[i];
        return max(a,b);
    }
}


vvi dp;
int ftd(vi &v,int i,int k){
    if(i==v.size()) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    if(k){
        int c = ftd(v,i+1,k); 
        int d = ftd(v,i+1,0) + v[i];
        return dp[i][k] = max(c,d);
    }
    else{
        int a = ftd(v,i+1,k); 
        int b = ftd(v,i+1,1) - v[i];
        return dp[i][k] = max(a,b);
    }
}


int main(){
    int n ;
    cin>>n;
    vi v(n);
    for(i,0,n){
        cin>>v[i];
    }

    // cout<<f(v,0,0);
    
    dp.resize(n+2,vi(5,-1));
    cout<<ftd(v,0,0);

    return 0;
}
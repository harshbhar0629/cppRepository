// https://leetcode.com/problems/unique-paths/
#include <iostream>
#include <vector>
using namespace std;

int path(int n,int m,int i,int j){
    if(i==n-1 and j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    return path(n,m,i+1,j) + path(n,m,i,j+1);
}

vector<vector<int>>dp;
int pathTD(int n,int m,int i,int j){
    if(i==n-1 and j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = pathTD(n,m,i+1,j) + pathTD(n,m,i,j+1);
}


int pathBU(int n,int m){
    dp.resize(n+1,vector<int>(m+1,0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int up = 0, down = 0;
            if(i-1>=0) up = dp[i-1][j];
            if(j-1>=0) down = dp[i][j-1];
            if(i!=0 || j!=0){
                dp[i][j] = up+down;
            }
        }
    }
    return dp[n-1][m-1];
}



int pathBUopt(int n,int m){
    vector<int>prev(m,0);
    prev[0]=1;
    for(int i=0;i<n;i++){
        vector<int> v(m,0);
        for(int j=0;j<m;j++){
            if(i==0 and j==0){
                prev[0]=v[0]=1;
            }
            else{
                int a=0,b=0;
                if(i-1>=0) a= prev[j];
                if(j-1>=0) b= v[j-1];
                v[j] = a+b;
            }
        }
        prev = v;
    }
    return prev[m-1];
}


int main(){
    
    int n,m;
    cin>>n>>m;
    dp.resize(n+1,vector<int>(m+1,-1));
    // cout<<path(n,m,0,0);
    // cout<<pathTD(n,m,0,0);

    cout<<pathBUopt(n,m);

    return 0;
}
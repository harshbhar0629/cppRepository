// spoj
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


// it needs 4d dp but constraints are high so that we have to convert into 3d dp
int n,m;
int f(vector<vector<char>>&v,int i,int j,int i1,int j1){

    if(j1>=m || j>=m || i1>=n || i>=n) return -1e8;
    if(v[i][j]=='#' || v[i1][j1]=='#') return -1e8;

    if((i==n-1 and j==m-1)){
        return v[i][j]=='*';
    }

    int ans =0 ;
    if(i==i1 and j1==j){
        if(v[i][j]=='*') ans++;
    }
    else{
        if(v[i][j]=='*') ans++;
        if(v[i1][j1]=='*') ans++;
    }

    int a = f(v,i,j+1,i1+1,j1);
    int b = f(v,i,j+1,i1,j1+1);
    int c = f(v,i+1,j,i1+1,j1);
    int d = f(v,i+1,j,i1,j1+1);

    ans+= max({a,b,c,d});
   
    return ans;
}


int dp[105][105][105];
int ftd(vector<vector<char>>&v,int i,int j,int i1){
    int j1 = i+j-i1;
    if(j1>=m || j>=m || i1>=n || i>=n) return -1e8;
    if(v[i][j]=='#' || v[i1][j1]=='#') return -1e8;

    if((i==n-1 and j==m-1)){
        return v[i][j]=='*';
    }
    if(dp[i][j][i1]!=-1) return dp[i][j][i1];

    int ans =0 ;
    if(i==i1 and j1==j){
        if(v[i][j]=='*') ans++;
    }
    else{
        if(v[i][j]=='*') ans++;
        if(v[i1][j1]=='*') ans++;
    }

    int a = ftd(v,i,j+1,i1+1);
    int b = ftd(v,i,j+1,i1);
    int c = ftd(v,i+1,j,i1+1);
    int d = ftd(v,i+1,j,i1);

    ans+= max({a,b,c,d});
   
    return dp[i][j][i1] = ans;
}




/**
 * 
2
9 7
*........
.....**#.
..**...#*
..####*#.
.*.#*.*#.
...#**...
*........

5 5
.*.*.
*###.
*.*.*
.###*
.*.*.

ans -> 7 8
*/


int main(){

    int input;
    cin>>input;
    while(input--){
        cin>>m>>n;
        vector<vector<char>>v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                cin>>v[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        // cout<<f(v,0,0,0,0)<<"\n";
        cout<<"Ans-> "<<ftd(v,0,0,0)<<"\n"; 
    }

   


    return 0;
}
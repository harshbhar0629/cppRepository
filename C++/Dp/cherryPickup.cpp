// https://leetcode.com/problems/cherry-pickup/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int n,m;
ll dp[52][52][52][52];
ll f(vector<vector<ll>>&v,int i,int j,int i1,int j1){
    
    if(j1>=m || j>=m || i>=n || i1>=n) return -1e8;
    if(v[i][j]==-1 || v[i1][j1]==-1) return -1e8;
    if(i==n-1 and j==m-1){
        return v[i][j];
    }

    if(dp[i][j][i1][j1]!=-1) return dp[i][j][i1][j1];

    ll val =0;
    if(j1==j and i==i1){
        val+=v[i][j];
    }
    else{
       val+=v[i][j]+v[i1][j1];
    }

    ll a = f(v,i+1,j,i1+1,j1) ;
    ll b = f(v,i+1,j,i1,j1+1) ;
    ll c = f(v,i,j+1,i1+1,j1) ;
    ll d = f(v,i,j+1,i1,j1+1) ;

    val+= max({a,b,c,d});

    return dp[i][j][i1][j1] = val;
}





ll dpp[52][52][52];
ll f(vector<vector<ll>>&v,int i,int j,int i1){
    int j1 = i+j - i1; 
    if(j1>=m || j>=m || i>=n || i1>=n) return -1e8;
    if(v[i][j]==-1 || v[i1][j1]==-1) return -1e8;
    if(i==n-1 and j==m-1){
        return v[i][j];
    }

    if(dpp[i][j][i1]!=-1) return dpp[i][j][i1];

    ll val =0;
    if(j1==j and i==i1){
        val+=v[i][j];
    }
    else{
       val+=v[i][j]+v[i1][j1];
    }

    ll a = f(v,i+1,j,i1+1) ;
    ll b = f(v,i+1,j,i1) ;
    ll c = f(v,i,j+1,i1+1) ;
    ll d = f(v,i,j+1,i1) ;

    val+= max({a,b,c,d});

    return dpp[i][j][i1] = val;
}




/**3
3      
 0 1 -1
1 0 -1 
1 1 1  
[0,1,-1],
[1,0,-1],
[1,1,1]
 * [0,1,-1],
 * [1,0,-1],
 * [1,1,1]
*/

int main(){

    
    cin>>n>>m;
    
    vector<vector<ll>>v(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<v[i][j]<<"  ";
    //     }cout<<endl;
    // }

    memset(dp,-1,sizeof dp);
    int ans = f(v,0,0,0,0);
    ans = (ans<0) ? 0 : ans ;
    cout<<ans ;


    return 0;
}
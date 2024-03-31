// https://leetcode.com/problems/knight-probability-in-chessboard/description/
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;
#define dd double


dd dp[30][30][105];
dd f(int n,int k,int i,int j){
    if(i>=n || j>=n || i<0 || j<0) return 0;
    if(k==0) return 1;
    if(dp[i][j][k] > 0.9) return dp[i][j][k];

    dd ans = 0.0;
    ans += f(n, k-1, i-2, j-1)*(0.125);
    ans += f(n, k-1, i-2, j+1)*(0.125);
    ans += f(n, k-1, i-1, j-2)*(0.125);
    ans += f(n, k-1, i-1, j+2)*(0.125);
    ans += f(n, k-1, i+1, j-2)*(0.125);
    ans += f(n, k-1, i+1, j+2)*(0.125);
    ans += f(n, k-1, i+2, j-1)*(0.125);
    ans += f(n, k-1, i+2, j+1)*(0.125);

    return dp[i][j][k] = ans;
}



int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

/// @brief 
/// @param n denotes NxN chess board
/// @param dx denotes movement of knight in direction of x-axis
/// @param dy denotes movement of knight in direction of y-axis 
/// @param k denotes no of movement in chess board
/// @param i denotes current x-axis direction
/// @param j denotes current y-axis direction
/// @return 

dd ftd(int n,int k,int i,int j){
    if(i>=n || j>=n || i<0 || j<0) return 0;
    if(k==0) return 1;
    if(dp[i][j][k] > 0.9) return dp[i][j][k];

    dd ans = 0.0;

    for(int m=0; m<8; m++){
        ans += f(n, k-1, i+dx[m], j+dy[m]); 
    }

    return dp[i][j][k] = ans;
}



int main(){
    
    int n;
    cin>>n;
    int k;
    cin>>k;

    memset(dp,-1.0,sizeof dp);
    cout<<fixed<<setprecision(8)<<f(n,k,0,0);


    return 0;
}
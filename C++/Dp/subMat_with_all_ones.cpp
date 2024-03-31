// https://www.codingninjas.com/studio/problems/count-square-submatrices-with-all-ones_3751502
#include <bits/stdc++.h>
using namespace std;

int dp[55][55];
int f(int i,int j,vector<vector<int>>&mat){
    if(i>=mat.size() || j>=mat[0].size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int right = f(i,j+1,mat);
    int down = f(i+1,j,,mat);
    int diagonal = f(i+1,j+1,mat);

    if(mat[i][j]==1){
        return dp[i][j] = 1+ min({right, down , diagonal});
    }
    return dp[i][j] = 0;
}


int countSquares(int n, int m, vector<vector<int>> &mat) {
    
    int dp[n][m];

    int ans=0;
    for(int i=0; i<n; i++) dp[i][0] = mat[i][0];
    
    for(int j=0; j<m; j++) dp[0][j] = mat[0][j];
        
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j] == 0) dp[i][j]=0;
            else{
                dp[i][j] = 1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans+=dp[i][j];    
        }
    }
    return ans;
}


int main(){
    

    return 0;
}
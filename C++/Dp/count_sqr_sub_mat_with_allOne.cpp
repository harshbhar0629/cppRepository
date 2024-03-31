#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
class Solution {

    int maxi=0;
    int dp[305][305];
    int f(vector<vector<int>>& mat, int i,int j){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int right = f(mat, i, j+1);        
        int down = f(mat, i+1, j);        
        int diagonal = f(mat, i+1, j+1);

        if(mat[i][j] == 1){
            dp[i][j] = 1+ min({right, down, diagonal});
            maxi += dp[i][j];
            return dp[i][j];
        }
        else return dp[i][j] = 0;
    }

public:
    int countSquares(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);
        memset(dp, -1, sizeof dp);
        maxi = 0;
        f(mat, 0 ,0);
        return maxi;
    }
};


// https://leetcode.com/problems/maximal-square/
class Solution {

    int maxi=0;
    int dp[305][305];
    int f(vector<vector<char>>& mat, int i,int j){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int right = f(mat, i, j+1);        
        int down = f(mat, i+1, j);        
        int diagonal = f(mat, i+1, j+1);

        if(mat[i][j]=='1'){
            dp[i][j] = 1+ min({right, down, diagonal});
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else return dp[i][j] = 0;
    }

public:
   
    int maximalSquare(vector<vector<char>>& mat) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);
        memset(dp, -1, sizeof dp);
        maxi = 0;
        f(mat, 0 ,0);
        return maxi*maxi;
    }
};

int main(){
    

    return 0;
}
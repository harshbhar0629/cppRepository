// https://leetcode.com/problems/spiral-matrix/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
     
        int n = mat.size() ,m = mat[0].size();
    
        int rowStart=0, rowEnd = n-1 , step = 1;
        int colStart =0 , colEnd = m-1;
        vector<int>res ;

        while(rowStart<=rowEnd and colStart<=colEnd){
            for(int i=colStart; i<=colEnd; i++){
                res.push_back(mat[rowStart][i]);
                step++;
            }
            rowStart++;
            if(step>m*n) break;
            for(int j=rowStart; j<=rowEnd; j++){
                res.push_back(mat[j][colEnd]);
                step++;
            }
            if(step>m*n) break;
            colEnd--;
            for(int j=colEnd; j>=colStart; j--){
                res.push_back(mat[rowEnd][j]);
                step++;
            }
            rowEnd--;
            if(step>m*n) break;
            for(int j=rowEnd; j>=rowStart; j--){
                res.push_back(mat[j][colStart]);
                step++;
            }
            if(step>m*n) break;
            colStart++;
        }
        return res;
    }
};

int main(){
    

    return 0;
}
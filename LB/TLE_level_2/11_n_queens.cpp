#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/n-queens/description/


class Solution {

    bool canPlaceQueen(int i, int j, int n, vector<string>& queens){
        //left diagonal
        for(int r = i, c=j; r>=0 and c>=0; r--, c--){
            if(queens[r][c] == 'Q'){
                return false;
            }
        }

        //right diagonal
        for(int r=i, c=j; r>=0 and c<n; r--, c++){
            if(queens[r][c]=='Q'){
                return false;
            }
        }

        //vertical direction
        for(int r=i; r>=0; r--){
            if(queens[r][j] == 'Q'){
                return false;
            }
        }

        return true;
    }


    void f(int i, const int n, vector<string>& queens, vector<vector<string>>& output){
        if(i==n){
            output.push_back(queens);
            return;
        }
        for(int j=0; j<n; j++){
            //check is place is eligible to place queen or not
            if(canPlaceQueen(i, j, n, queens)){
                //if this is empty space and having no issue of attacking then we can place our queen
                queens[i][j] = 'Q';
                // try to place another queen 
                f(i+1, n, queens, output);
                //if we r not able to place queen then backtrack and try next place 
                queens[i][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        if(n==1){
            return {{"Q"}};
        }
        if(n==2 || n==3) {
            return {};
        }
        vector<string>queens(n, string(n,'.'));
        vector<vector<string>>output;
        f(0, n, queens, output);

        return output;
    }
};


int main(){
    

    return 0;
}
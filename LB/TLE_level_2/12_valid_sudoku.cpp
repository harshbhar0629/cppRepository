#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/valid-sudoku/


class Solution {

    bool isValid(int r, int c, vector<vector<char>>& board){
        char ch = board[r][c];
        for(int i=0; i<9; i++){
            if(r!=i and board[i][c] == ch){
                return false;
            }
            if(c!=i and board[r][i] == ch){
                return false;
            }
        }
        int x = 3*(r/3);
        int y = 3*(c/3);

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i+x!=r and c!=j+y and board[i+x][j+y] == ch){
                    return false;
                }
            }
        }

        return true;
    }
    
    // bool f(vector<vector<char>>& board, int i, int j){
    //     if(i==9){
    //         return true;
    //     }
    //     if(j==9){
    //         return f(board, i+1, 0);
    //     }
    //     if(board[i][j] != '.'){
    //         bool res = isValid(i, j, board);
    //         if(res){
    //             return f(board, i, j+1);
    //         }
    //         return false;
    //     }
    //     else{
    //         return f(board, i, j+1);
    //     }
    // }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.' and !isValid(i, j, board)){
                    return false;
                }
            }
        }
        return true;
    }
};


int main(){
    

    return 0;
}
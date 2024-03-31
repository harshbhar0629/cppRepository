#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sudoku-solver/


class Solution {

    bool isPossible(int r, int c, char ch, vector<vector<char>>& board){
        // char ch = num + '0';
        // checking for row
        // checking for column
        for(int i=0; i<9; i++){
            if(board[i][c] == ch){
                return false;
            }
            if(board[r][i] == ch){
                return false;
            }
        }
       
        int x = (r/3)*3;
        int y = (c/3)*3;
        //checking 3x3 matrix
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i+x][j+y]==ch){
                    return false;
                }
            }
        }
        //all conditions satisfied 
        return true;
    }

// 9^9
    bool f(vector<vector<char>>& board, int r, int c){
        if(r==9){
            return true;
        }
        if(c==9){
            return f(board, r+1, 0);
        }
        if(board[r][c] != '.') {
            return f(board, r, c+1);
        }

        for(char j='1'; j<='9'; j++){
           
            if(isPossible(r, c, j, board)){
                board[r][c] = j ;
                if(f(board, r, c+1)) 
                    return true;;
                board[r][c] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        f(board, 0, 0);
    }
};


int main(){
    

    return 0;
}
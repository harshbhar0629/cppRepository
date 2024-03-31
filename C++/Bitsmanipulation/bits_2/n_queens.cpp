#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/n-queens/description/

class Solution
{

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

    void f1(int i, const int n, vector<string>& queens, vector<vector<string>>& output){
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
                f1(i+1, n, queens, output);
                //if we r not able to place queen then backtrack and try next place
                queens[i][j] = '.';
            }
        }
    }

    int left[20];
    int right[20];
    int col[10];

    void f(int i, int n, vector<string> &queens, vector<vector<string>> &output, int left = 0, int right = 0, int col = 0)
    {
        if (i == n)
        {
            output.push_back(queens);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            bool l = ((left & (1 << (n - i + j))) == 0) ? 1 : 0;
            bool r = ((right & (1 << (i + j))) == 0) ? 1 : 0;
            bool c = ((col & (1 << j)) == 0) ? 1 : 0;
            if (l and r and c)
            {
                queens[i][j] = 'Q';
                left |= (1 << (n - i + j));
                right |= (1 << (i + j));
                col |= (1 << j);
                f(i + 1, n, queens, output, left, right, col);
                queens[i][j] = '.';
                left ^= (1 << (n - i + j));
                right ^= (1 << (i + j));
                col ^= (1 << j);
            }
        }

        // for(int j=0; j<n; j++){
        //     if(left[n-i+j] == -1 and right[i+j] == -1 and col[j] == -1){
        //         queens[i][j] = 'Q';
        //         left[n-i+j] = right[i+j] = col[j] = 1;
        //         f(i+1, n, queens, output);
        //         queens[i][j] = '.';
        //         left[n-i+j] = right[i+j] = col[j] = -1;
        //     }
        // }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // if(n==1){
        //     return {{"Q"}};
        // }
        // if(n==2 || n==3) {
        //     return {};
        // }
        // vector<string>queens(n, string(n,'.'));
        // vector<vector<string>>output;
        // f1(0, n, queens, output);

        // return output;

        if (n == 1)
        {
            return {{"Q"}};
        }
        if (n == 2 || n == 3)
        {
            return {};
        }

        vector<string> queens(n, string(n, '.'));
        vector<vector<string>> output;
        memset(left, -1, sizeof left);
        memset(right, -1, sizeof right);
        memset(col, -1, sizeof col);

        f(0, n, queens, output, 0, 0, 0);
        return output;
    }
};

int main(){
    ;

    return 0;
}
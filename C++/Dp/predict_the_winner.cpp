// https://leetcode.com/problems/predict-the-winner/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    bool win(int ans, int total){
        // cout<<ans<<endl;
        //total - ans is score of player2 and ans is score of player1
        return ans>=total-ans;
    }

    int f(vector<int>& v, int start, int end, int total){
        if(start>end){
            return 0; 
        }
        return total - min(f(v, start+1, end, total-v[start]) , f(v, start, end-1, total-v[end]));
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        return win(f(nums, 0, nums.size()-1, total), total);
    }
};


class Solution {

    // this function returns score of player 1
    int dp[25][25];
    int f(vector<int>& v, int i, int j){
        if(i>j){
            return 0; 
        }
        if(i==j) return v[i];
        if(dp[i][j]!=-1) return dp[i][j];

    //first take ith element and call for its next ith element that player1 can pick 
        int take_ith_ele = v[i] + min(f(v, i+2, j), f(v, i+1, j-1));  
        int take_jth_ele = v[j] + min(f(v, i, j-2), f(v, i+1, j-1));

        return dp[i][j] = max(take_ith_ele, take_jth_ele);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int score_player1 = f(nums, 0, nums.size()-1);
        int score_player2 = total - score_player1;

        return score_player1>=score_player2;
    }
};

class Solution {

    // this function returns score of player 1
    int dp[25][25];
    int f(vector<int>& v, int i, int j){
        if(i>j){
            return 0; 
        }
        if(i==j) return v[i];
        if(dp[i][j]!=-1) return dp[i][j];

    //first take ith element and call for its next ith element that player1 can pick 
        int take_ith_ele = v[i] - f(v, i+1, j); 
        int take_jth_ele = v[j] - f(v, i, j-1);

        return dp[i][j] = max(take_ith_ele, take_jth_ele);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return f(nums, 0, nums.size()-1) >= 0;
    }
};


int main(){
    

    return 0;
}
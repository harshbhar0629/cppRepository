// https://leetcode.com/problems/delete-and-earn/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    int freq[10005], dp[10005];
    int f(int i){
        if(i>=10005){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(freq[i] + f(i+2), f(i+1));
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        memset(freq, 0, sizeof freq);
        for(auto& x: nums){
            freq[x] += x;
        }

        return f(0);
    }
};


int main(){
    

    return 0;
}
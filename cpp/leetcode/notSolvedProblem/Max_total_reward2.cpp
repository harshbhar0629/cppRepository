#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-total-reward-using-operations-ii/

class Solution
{
    // unordered_map<int,int>dp[50005];
    // int f(int i, vector<int>& v, int x){
    //     if(i==v.size()){
    //         return x;
    //     }
    //     if(dp[i][x] != 0){
    //         return dp[i][x];
    //     }

    //     int opt1 = f(i+1, v, x);
    //     int opt2 = 0;
    //     if(v[i] > x){
    //         opt2 = f(i+1, v, x+v[i]);
    //     }

    //     return dp[i][x] = max(opt1, opt2);
    // }

public:
    int maxTotalReward(vector<int> &rewardValues)
    {
        // sort(rewardValues.begin(), rewardValues.end());
        // set<int>s(rewardValues.begin(), rewardValues.end());

        // vector<int>v;
        // for(auto it: s){
        //     v.push_back(it);
        // }

        // return f(0, v, 0);

        const int N = 1e5;
        const int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        bitset<N> bs, mask;
        int j = 0;
        bs.set(0);

        for (int i = 0; i < n; i++)
        {
            while (j < rewardValues[i])
            {
                mask[j] = 1;
                j++;
            }
            bs |= ((mask & bs) << rewardValues[i]);
        }

        for (int i = N - 1; i >= 1; i--)
        {
            if (bs[i] == 1)
            {
                return i;
            }
        }

        return 0;
    }
};

int main(){
    

    return 0;
}
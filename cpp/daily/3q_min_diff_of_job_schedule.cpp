// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    int n;
    int dp[305][15];
    int f(vector<int>& v, int idx, int d){
        if(d==1) {
            int m = INT_MIN;
            for(int i= idx; i<n; i++){
                m = max(m,v[i]);
            }
            return m;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];

        int maxi = v[idx], ans = INT_MAX;

        for(int i=idx; i<=n-d; i++){
            maxi = max(maxi, v[i]);
            int res = maxi + f(v, i+1, d-1);
            ans = min(ans, res);
        }

        return dp[idx][d] = ans;
    }


public:
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        if(d>n) return -1;

        memset(dp ,-1, sizeof dp);
        return f(jd ,0, d);
    }
};


int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


class Solution {

    int dp[100005][3];
    int f(vector<int>&v1, vector<int>&v2, int i, bool swapped){
        if(i==v1.size()) return 0;
        if(dp[i][swapped]!=-1) return dp[i][swapped];

        int prev1 = v1[i-1];
        int prev2 = v2[i-1];
        int ans = INT_MAX;

        if(swapped) swap(prev1, prev2);

    // No swap case
        if(prev1 < v1[i] and prev2 < v2[i]){
            ans = f(v1, v2, i+1, 0);
        } 

        // swap case 
        if(prev2 < v1[i] and prev1 < v2[i]){
            ans = min(ans, 1+ f(v1, v2 , i+1, 1)); 
        }

        return dp[i][swapped] = ans;
    }

    int fbu(vector<int>& v1, vector<int>& v2){

        int n = v1.size();
        memset(dp, 0, sizeof dp);

        for(int i=n-1; i>=1; i--){
            for(int j=1; j>=0; j--){

                int prev1 = v1[i-1];
                int prev2 = v2[i-1];
                int ans = INT_MAX;

                if(j) swap(prev1, prev2);
                // No swap case
                if(prev1 < v1[i] and prev2 < v2[i]){
                    ans = dp[i+1][0];
                } 

                // swap case 
                if(prev2 < v1[i] and prev1 < v2[i]){
                    ans = min(ans, 1+ dp[i+1][1]); 
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][0];
    }

    int fbuOpt(vector<int>& v1, vector<int>& v2){

        int n = v1.size();
        // memset(dp, 0, sizeof dp);
        vector<int>prev(2,0), curr(2,0);

        for(int i=n-1; i>=1; i--){
            for(int j=1; j>=0; j--){

                int prev1 = v1[i-1];
                int prev2 = v2[i-1];
                int ans = INT_MAX;

                if(j) swap(prev1, prev2);
                // No swap case
                if(prev1 < v1[i] and prev2 < v2[i]){
                    ans = prev[0];
                } 

                // swap case 
                if(prev2 < v1[i] and prev1 < v2[i]){
                    ans = min(ans, 1+ prev[1]); 
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[0];
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return  f(nums1, nums2, 1, 0);
    }
};


int main(){
    

    return 0;
}
// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
     
        for(int i=0; i<=n; i++){

            int start = max(0, i - ranges[i]);
            int end = min(n , i + ranges[i]);
            int ans = INT_MAX;
            for(int j= start; j<=end; j++){
                ans = min(ans,dp[j]);
            }

            if(ans!=INT_MAX){
                dp[end] = min(ans+1,dp[end]);
            }
        }
        cout<<dp[n];
        
        return (dp[n] == INT_MAX) ? -1 : dp[n];
    }
};


int main(){

    int n;
    cin>>n;
    vector<int>v(n+1);
    cout<<"Enter "<<n+1<<" values: ";
    for(int int i=0;i<=n;i++){
        cin>>v[i];
    }

    Solution s;
    cout<<s.minTaps(n,v);


    return 0;
}
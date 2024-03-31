// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dp[50][50];
int fbuSubArray(vector<int>& nums1,vector<int>& nums2){

    int n = nums1.size();
    int m = nums2.size();
    
    memset(dp, 0, sizeof dp);
    int ans = 0 ;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(nums1[i-1] == nums2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(dp[i][j],ans);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;

}



int fbuSubArrayOpt(vector<int>& nums1,vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();
    
    vector<int> curr(m+5,0),prev(m+5,0); 
    // memset(dp, 0, sizeof dp);
    int ans = 0 ;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(nums1[i-1] == nums2[j-1]){
                curr[j] = 1 + prev[j-1];
                ans = max(curr[j],ans);
            }
            else{
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return ans;
}



int main(){
    
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int>v(n),v1(m);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    for(int j=0; j<m; j++){
        cin>>v1[j];
    }

    cout<<fbuSubArray(v,v1);

    return 0;
}
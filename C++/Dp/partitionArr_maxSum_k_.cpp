// https://leetcode.com/problems/partition-array-for-maximum-sum/
#include <bits/stdc++.h>
using namespace std;


int n;
int dp[505];
int f(vector<int>& v,int k ,int i){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    
    int maxVal=-1,maxSum=-1;
    for(int j=i; j<min(n,i+k); j++){
        maxVal = max(maxVal,v[i]);
        int sum = (j-i+1)*maxVal + f(v,k,j+1);
        maxSum = max(maxSum,sum);
    }

    return dp[i] = maxSum;
}


 int maxSumAfterPartitioning(vector<int>& arr, int k) {

    n = arr.size();
    memset(dp,0,sizeof dp);

    for(int i=n-1; i>=0; i--){

        int maxVal = -1, maxSum = -1;
        for(int j=i; j<min(n,i+k); j++){

            maxVal = max(maxVal,arr[j]);
            int sum = (j - i + 1)*maxVal + dp[j+1];
            maxSum = max(maxSum,sum);
        }
        dp[i] = maxSum;
    }
    
    return dp[0];
}


int main(){
    

    return 0;
}
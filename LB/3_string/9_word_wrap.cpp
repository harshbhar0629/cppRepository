// https://practice.geeksforgeeks.org/problems/word-wrap1646/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    int dp[505][2005];
    int f(vector<int>& arr, int i, int rem, int &k){
        // if i is exhaust then no cost required
        if(i==arr.size()) return 0;
        if(dp[i][rem]!=-1) return dp[i][rem];
        
        int ans = 0;
        if(arr[i]>rem){
        // we will always substract space from the remaining and suppose that case if we not 
        // found a string that can set in remaining portion so that we have to take back that space 
            ans = (rem+1)*(rem+1) + f(arr, i+1, k-arr[i]-1, k);
        // why k-rem-1
        //-> bcoz k is total space now in remining portion not have much space to adjust curr string
        //so we will take new remaining by minus in k
        }
        else{
            //if we have space to adjust curr string
            int choice1 = f(arr, i+1, rem-arr[i]-1, k);
            //we have space but we have to explore all positbilities so don't 
            // take same space we require a different line
            int choice2 = (rem+1)*(rem+1) + f(arr, i+1, k-arr[i]-1, k);
            ans = min(choice1, choice2);
        }
        
        return dp[i][rem] = ans;
    }
    
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp, -1, sizeof dp);
        return f(nums, 0, k,  k);
    } 
};

int main(){
    

    return 0;
}
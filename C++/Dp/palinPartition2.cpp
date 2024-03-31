// https://leetcode.com/problems/palindrome-partitioning-ii/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
    
    int dp[2005];

    int f(string& s,int i){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int minCost = INT_MAX;

        for(int j=i; j<s.size(); j++){
            if(isPalindrome(i,j,s)){
                int cost = 1+ f(s,j+1);
                minCost =  min(minCost,cost); 
            }
        }
        return dp[i] = minCost;
    }
   
    bool isPalindrome(int i,int j,string& s){

        while(i<j){
            if(s[i]!=s[j]) return  false;
            i++,j--;
        }

        return  true;
    }
public:
    int minCut(string s) {

        memset(dp,0,sizeof dp);
       
        int n = s.size();

        for(int i=n-1; i>=0; i--){
            int minCost = INT_MAX;
            for(int j=i; j<s.size(); j++){
               
                if(isPalindrome(i,j,s)){
                    int cost = 1+ dp[j+1];
                    minCost =  min(minCost,cost); 
                }
            }
            dp[i] = minCost;
        }
    
        return dp[0]-1;
    }
};


int main(){
    

    return 0;
}
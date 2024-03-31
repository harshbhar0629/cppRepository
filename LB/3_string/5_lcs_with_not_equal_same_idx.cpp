// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
        int dp[1005][1005];
        int f(string &s, int i, int j){
            if(i>=s.size() || j>=s.size()) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            
            if(s[i]==s[j] and i!=j){
                return dp[i][j] = 1+ f(s, i+1,j+1);
            }
            else {
                return dp[i][j] = max(f(s,i+1,j), f(s,i,j+1));
            }
        }
    
	public:
		int LongestRepeatingSubsequence(string str){
		    memset(dp, -1, sizeof dp);
		    return f(str,0,0);
		}

};

int main(){
    

    return 0;
}
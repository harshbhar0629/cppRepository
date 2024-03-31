// https://leetcode.com/problems/shortest-common-supersequence/description/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


// if we want to find the length of common subseq then size of str1 and str2 - of lcs of both string
int dp[105][105];
string fbu(string s,string t){

    memset(dp,0,sizeof dp);
    int n = s.size();
    int m = t.size();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string res="";
    int i=n,j=m;

    while(i>0 and j>0){
        if(s[i-1] == t[j-1]){
            res+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            res+=t[j-1];
            j--;
        }
        else {
            res+=s[i-1];
            i--;
        }
    }

    while(i>0){
        res+=s[i-1];
        i--;
    }

    while(j>0){
        res+=t[j-1];
        j--;
    }

    reverse(res.begin(),res.end());

    return res;

}



int main(){
    string s,t;
    cin>>s>>t;

    cout<<fbu(s,t);

    return 0;
}
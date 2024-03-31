// https://practice.geeksforgeeks.org/problems/shortest-uncommon-subsequence5746/1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// int f(string& s,string& t,int i,int j ){
//     // if j is not reach our end and string s will complete then this will never give me uncommon; 
//     if(i==s.size()) return 1000;
//     // if j reach our end but i not reach our end then then we have to include ith character
//     if(j>=t.size()) return 1;

//     int k=j;
//     for(;k<t.size();k++){
//         if(s[i]==t[k]) break;
//     }
//     if(k==t.size()) return 1;
//     return min(f(s,t,i+1,j) , 1+f(s,t,i+1,j+k+1));
// }


int dp[100][100];
int ftd(string &s, string &t, int i, int j){
    //Why this?
    //This is because if we reach end of the string it means -> we were not able to find a subsequence which was not common
    if(i >= s.size()){
        return 501;
    }
    //Now if i is not reached at end yet but j is reached we can definitely say that if now I take ith character in our subsequence, it will definitely create an uncommon subsequence
    if(j >= t.size()){
        return 1;
    }
    //if we already know that for particular i, j position, what is the minimum length of the uncommon subsequence then return it
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //Suppose any of the above condition is not true, we will try to find current ith character in T string starting from j,
    int k = j;
    for(; k < t.size(); k++){
        //if we find the character, it gives us two options -> either take that character in the uncommon subsequence and increase j to k + 1 and check to next character or don't add to subsequence and check for next character
        if(s[i] == t[k]){
            break;
        }
    }
    //or in case we did not find the ith character of S in T, then it's sure that we will get the uncommon subsequence by adding that character to our current ans
    if(k == t.size()){
        return 1;
    }
    return dp[i][j] = min(ftd(s,t, i + 1, j), 1 + ftd(s,t, i + 1, k + 1));
}


int fbu(string s,string t){

    int n =s.size();
    int m = t.size();
    // dp.resize(n+2,vector<int>(m+2,1000));
    memset(dp,1000,sizeof dp);

    for(int i=0;i<n;i++){
        dp[i][m]=1;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){

            int k=j;
            while(k<m and s[i]!=t[k]) 
                k++;

            if(k==m){
                dp[i][j]=1;
            }
            else{
                dp[i][j] = min(dp[i+1][j] , 1+ dp[i+1][k+1]);
            }
        }
    }

    return (dp[0][0] >= 1000)? -1 : dp[0][0];

}

int main(){
    string s ,t;
    cin>>s>>t;

    // cout<<f(s,t,0,0);

    // int ans =f(s,t,0,0);
    // (ans==1000)? cout<<"-1" : cout<<ans;

    // cout<<endl;

    // memset(dp,-1,sizeof dp);
    // int ans = ftd(s,t,0,0);
    // (ans==1000)? cout<<"-1" : cout<<ans;

    cout<<fbu(s,t);

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int dp[1005][1005];
int fbu(string s){

    int n = s.size();
    string t = s;
    int ans = 0 ;

    reverse(s.begin(),s.end());
    memset(dp,0,sizeof dp);
    

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){

            if(s[i]==t[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
                ans = max(ans,dp[i][j]); 
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;

}



string fbuPrint(string s){

    int n = s.size();
    string t = s;
    int ans = 0 ;
    int row=0,col=0;

    reverse(s.begin(),s.end());
    memset(dp,0,sizeof dp);
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                if(ans<dp[i][j]){
                    ans = dp[i][j];
                    row=i;
                    col=j;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    if(ans==0) return "";
    cout<<ans;
    char res[ans+1];
    res[ans] = '\0';
    while(dp[row][col]!=0){
        
        res[--ans] = s[row-1];
        
        row--;
        col--;
    }
    
    return res;
}




int main(){
    string s;
    cin>>s;

    cout<<fbuPrint(s);

    return 0;
}
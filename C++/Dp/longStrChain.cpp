// https://leetcode.com/problems/longest-string-chain/
#include <bits/stdc++.h>
using namespace std;


static bool cmp(string& s ,string& t){
    return s.size()<t.size();
}

bool checkPossible(string &s, string& t){
    if(s.size()!=t.size()+1) return false;
    int i = 0, j = 0;
    while(i<s.size()){
        if(j<t.size() and s[i]==t[j]){
            i++;
            j++;
        } else{
            i++;
        }
    }
    if(i==s.size() and t.size()==j) return true;
    return false;
}

int f(vector<string>&v){
    int n = v.size();
    sort(v.begin(),v.end(),cmp);
    vector<int>dp(n,1);
    int maxi = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(checkPossible(v[i],v[j]) and dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
        maxi = max(dp[i],maxi);
    }
    return maxi;
}


int main(){
    int n ;
    cin>>n;
    vector<string>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<f(v);

    return 0;
}
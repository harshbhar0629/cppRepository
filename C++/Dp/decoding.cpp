// https://www.spoj.com/problems/ACODE/
#include <iostream>
#include <vector>
using namespace std;
#define ll long long int


vector<ll> dp;
ll ftd(string &s, int i)
{
    if(i<=0) return (ll)1;
    if(dp[i]!=-1) return dp[i];

    ll ans =0;
    if(s[i] - '0' >0){
        ans+=ftd(s,i-1);
    }
    if(s[i-1] - '0' > 0 and ((s[i-1] - '0')*10 + (s[i] - '0')) <= 26){
        ans+=ftd(s,i-2);
    }  
    return dp[i] = ans;
}


ll f(string& s,int i){
    if(i<=0) return 1;

    ll ans =0;
    if(s[i] - '0' >0){
        ans += f(s,i-1);
    }
    if(s[i-1] - '0' > 0 and (s[i-1] - '0')*10 + (s[i] - '0') <= 26){
        ans+=f(s,i-2);
    }
    return ans;
}


ll fbu(string s){

    dp.resize(100,0);
    dp[0] = s[0]!='0';
    if(s.size()>1){
        if(s[1] != '0') dp[1] += dp[0];
        if(s[0] - '0' > 0 and (s[0] - '0')*10 + (s[1] - '0') <= 26){
            dp[1]++;
        }
    }
   

    for(int i=2; i<s.size(); i++){
        ll ans =0;
        if(s[i] - '0' >0){
            ans += dp[i-1];
        }
        if(s[i-1] - '0' > 0 and (s[i-1] - '0')*10 + (s[i] - '0') <= 26){
            ans += dp[i-2];
        }
        dp[i] = ans;
    }
    return dp[s.size()-1];
}


int main()
{
    string s;
    cin >> s;
    // dp.resize(100, -1);
    // cout << ftd(s, s.size()-1);

    cout<<fbu(s);

    return 0;
}
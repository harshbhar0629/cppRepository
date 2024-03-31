#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/sum-string3151/1

#define ll long long int
class Solution{
    
    int dp[505];
    bool f(string &s, int curr){
        if(curr<=0) return 1;
        if(dp[curr]!=-1) return dp[curr];
        
        for(int i=curr; i>1; i--){
            for(int j=i-1; j>0; j--){
                string s3 = s.substr(i, curr-i+1);
                string s2 = s.substr(j, i-j);
                if(s3.size() > 15 || s2.size()>15){
                    break;
                }
                if(s3[0]=='0' || s2[0]=='0') continue;
                ll sum = stoll(s3);
                ll b = stoll(s2);
                ll a = sum-b;
                if(a>=0){
                    string a1 = to_string(a);
                    int req = a1.size();
                    if(j>=req){
                        int start = j-req;
                        string a2 = s.substr(start, req);
                        // cout<<a1<<" "<<a2<<" "<<s2<<" "<<s3<<endl; 
                        if(a1==a2){
                            if(start==0) return dp[curr] = 1;
                            if(f(s, i-1)) return dp[curr] = 1;
                        }
                    }
                }
            }
        }
        return dp[curr] = 0;
    }
    
public:
    int isSumString(string s){
        if(s.size()<=2) return 0;
        memset(dp, -1, sizeof dp);
        return f(s, s.size()-1);
    }
};



int main(){
    

    return 0;
}
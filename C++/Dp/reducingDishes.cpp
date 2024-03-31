#include <bits/stdc++.h>
using namespace std;


class Solution {

    int dp[505][505];
    // int f(vector<int>&v ,int i, int time){
    //     if(i==v.size()) return 0;
    //     if(dp[i][time]!=-1) return dp[i][time];

    //     int exclude = f(v, i+1, time);
    //     int include = f(v, i+1, time+1) + v[i]*(time+1);

    //     return dp[i][time] = max(include, exclude);
    // }

    static bool cmp(int &a,int &b){
        return a<b;
    }

    int fbu(vector<int>&v){
        
        sort(v.begin(), v.end(), cmp);
        memset(dp,0,sizeof dp);
        int n = v.size();

        for(int i=n-1; i>=0; i--){
            for(int time = n-1; time>=0; time--){

                int exclude = dp[i+1][time];
                int include = dp[i+1][time+1] + v[i]*(time+1);
                dp[i][time] = max(include, exclude);             
            }
        }
        
        return dp[0][0];
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {

        // sort(satisfaction.begin(), satisfaction.end(), cmp);
        // memset(dp,-1,sizeof dp);

        // return fbu(satisfaction);
        // return f(satisfaction,0,0);

        // int n=satisfaction.size();
        // sort(satisfaction.begin(),satisfaction.end()); 
        // int idx=0;
        // int count=1;
        // int ans=0;
        // for(int i=n-1;i>=0;i--){
        //     ans+=satisfaction[i];
        //     if(ans<0){
        //         idx=i+1;
        //         break;
        //     }
        // }
        // ans=0;
        // for(int i=idx;i<n;i++){
        //     ans+= count*satisfaction[i];
        //     count++;
        // }
        // return ans;

        // int n=satisfaction.size();
        // sort(satisfaction.begin(),satisfaction.end());
        // int ans=0,count=1,finalans=0;
        // for(int i=0;i<n;i++){
        //     ans=0,count=1;
        //     for(int j=i;j<n;j++){
        //        ans+= satisfaction[j]*count;
        //        count++;
        //     }
        //     finalans=max(ans,finalans);
        // }
        // // if(ans<=0) return 0;
        // return finalans;
    }
};


int main(){
    

    return 0;
}
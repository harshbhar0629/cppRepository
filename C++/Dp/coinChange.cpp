// https://leetcode.com/problems/coin-change/description/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int count=0;
class solution{

    int solveRec(vector<int>&coin,int target){
        if(target==0){
            count++;
            return 0;
        }
        if(target < 0) {
            return INT_MAX;
        }

        int mini = INT_MAX;

        for(int i=0; i<coin.size(); i++){
            if(target - coin[i] < 0) continue;
            int ans = solveRec(coin,target-coin[i]);
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        return mini;
    }

    vector<int> dp;
    int solveRecOpt(vector<int>& coin,int target){
        if(target==0){
            return 0;
        }
        if(target < 0) {
            return INT_MAX;
        }
        if(dp[target] != -1) {
            return dp[target];
        }

        int mini = INT_MAX;
        
        for(int j=0; j<coin.size(); j++){
            if(target-coin[j] < 0) continue;
            int ans = solveRecOpt(coin,target-coin[j]);
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        dp[target] = mini;
        return dp[target];
    }

    int bottomUp(vector<int>&coin , int target){
        dp.resize(target+1,INT_MAX);
      
        for(int i=1; i<=target; i++){
            for(int j=0; j<coin.size(); j++){
      
                if(i-coin[j] >= 0 and dp[i-coin[j]] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-coin[j]] +1);
                }
            }
        }
        return dp[target];
    }

public:

    int coinChange(vector<int>& coins, int amount) {

        int ans = solveRec(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;   
        
        // dp.resize(amount+1,-1);
        // int ans = solveRecOpt(coins,amount);
        // if(ans==INT_MAX) return -1;
        // return ans;

        // int ans = bottomUp(coins,amount);
        // if(ans==INT_MAX) return -1;
        // return ans;
    }

};

int main(){
    vector<int> v={2,3,5};
    int k =9;
    solution a;
    int ans = a.coinChange(v,k);
    cout<<ans<<endl<<count;
    return 0;
}
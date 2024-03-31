// https://atcoder.jp/contests/dp/tasks/dp_a
#include <iostream>
#include <vector>
using namespace std;

// top down
vector<int>h;
int n;
int minCostToJump(int i){
    if(i==n-1) return 0;
    if(i==n-2) return  minCostToJump(i+1) + abs(h[i] - h[i+1]);
    return min( abs(h[i]-h[i+1]) + minCostToJump(i+1) , abs(h[i]-h[i+2]) + minCostToJump(i+2) );
}


vector<int> dp;
int minCostToJumpOptimised(int i){
    if(i==n-1) return 0;
    if(dp[i]!=-1) return dp[i];
    if(i==n-2) return  minCostToJumpOptimised(i+1) + abs(h[i] - h[i+1]);
   
    dp[i] = min(minCostToJumpOptimised(i+1) + abs(h[i] - h[i+1]) , minCostToJumpOptimised(i+2) + abs(h[i]-h[i+2]));
    return dp[i];
}


// bottom up 
int minCostBottomUp(){

    int n = h.size();
    dp.resize(n,1000000);
    dp[n-1] = 0;

    for(int i = n-2; i>=0; i--){
        if(i==n-2){
            dp[i] = min(dp[i], abs(h[i]-h[i+1]));
        }
        else{
            dp[i] = min(abs(h[i]-h[i+1]) + dp[i+1], dp[i+2] + abs(h[i]-h[i+2]));
        }
    }
    return dp[0];
}

int fbu(){
    int n = h.size();
    int p1= 0;
    int p2=100000;
    for(int i=n-2;i>=0;i--){
        if(i==n-2){
            int curr = p1 + abs(h[i]-h[i-1]);
            p2 = p1;
            p1=curr;
        }
        else{
            int curr = min(p1 + abs(h[i]-h[i-1]) , p2 + abs(h[i]-h[i-2]));
            p2 = p1;
            p1=curr;
        }
    }
    return p1;
}

int main(){
    
    cin>>n;
    h.resize(n);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    
      cout<<minCostToJump(0)<<endl;

    //2->  dp.resize(n,-1);
    // cout<<minCostToJumpOptimised(0)<<endl;

    // 3-> 
    // cout<<minCostBottomUp();

    return 0;
}
/**
 * 4
 * 10 30 40 20
 * 30
 * 
 * 6
 * 30 10 60 10 60 50
 * 40
*/
#include <iostream>
#include <vector>
using namespace std;


int f(vector<int>&v,int i,int sum){
    if(sum==0) return 1;
    if(i==v.size()-1) {
        if(v[i]==sum) return 1;
        else return 0;
    }
    if(sum<0) return 0;

    return f(v,i+1,sum-v[i]) + f(v,i+1,sum);
}


vector<int>dp;
int ftd(vector<int>&v,int i,int sum){

    /**
     * if array number also consider 0 then 
     * if(i==v.size()-1){
     *     if(sum==0 and v[i]==0) return 2;
     *     if(sum==0 || v[i]==sum) return 1;
     *     return 0;
     * }
    */

    if(sum==0) return 1;
    if(i==v.size()-1) {
        if(v[i]==sum) return 1;
        else return 0;
    }
    if(sum<0) return 0;
    if(dp[sum]!=-1) return dp[sum];

    return dp[sum] = ((v[i]<=sum) ? ftd(v,i+1,sum-v[i]) : 0) + ftd(v,i+1,sum);
}



int main(){

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }    
    int sum;
    cin>>sum;

    cout<<f(v,0,sum)<<endl;

    dp.resize(sum+2,-1);
    cout<<ftd(v,0,sum);

    return 0;
}
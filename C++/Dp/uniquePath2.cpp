// https://leetcode.com/problems/unique-paths-ii/description/
#include <iostream>
#include <vector>
using namespace std;

int f(vector<vector<int>>&v,int i,int j){
    if(i==v.size()-1 and j==v[0].size()-1) return 1;
    if(i>=v.size() || j>=v[0].size() || v[i][j]==-1 ) return 0;
    return f(v,i+1,j) + f(v,i,j+1);
}


vector<vector<int>>dp;
int ftd(vector<vector<int>>&v,int i,int j){
    if(i==v.size()-1 and j==v[0].size()-1) return 1;
    if(i>=v.size() || j>=v[0].size() || v[i][j]==-1 ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j] = ftd(v,i+1,j) + ftd(v,i,j+1);
}


int fbu(vector<vector<int>>&v){
    int n = v.size();
    int m = v[0].size();
    dp.resize(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==-1) dp[i][j]=0;
            else if(i==0 and j==0) dp[i][j]=1;
            else{
                int up=0,left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
    }
    return dp[n-1][m-1];
}


int fbuopt(vector<vector<int>> &v){
    int n = v.size();
    int m = v[0].size();
    vector<int>prev(m,0);
    for(int i=0;i <n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            if(v[i][j]==-1){
                temp[j]=0;
            }
            else if(i==0 and j==0){
                temp[j]=0;
                prev[j]=0;
            }
            else{
                int a =0,b=0;
                if(i>0) a= prev[j];
                if(j>0) b = temp[j-1];

                temp[j] = a+b;
            }
        }
        prev = temp;
    }
    return prev[m-1];
}

int main(){

    int n ,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    cout<<"enter -1 position: ";
    int x,y;
    cin>>x>>y;   
    v[x][y] =-1;

    // cout<<f(v,0,0);
    // dp.resize(n,vector<int>(m,-1));
    // cout<<ftd(v,0,0);

    cout<<fbu(v);

    return 0;
}
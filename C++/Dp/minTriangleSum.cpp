// https://www.codingninjas.com/studio/problems/triangle_1229398?leftPanelTab=1
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>&v ,int i,int j){
    if(i==v.size()-1){
        cout<<"hit "<<v[i][j]<<endl;
        return v[i][j];
    }
    if(i>=v.size() || j>=v[i].size()) return 1e5;
    return v[i][j] + min( f(v,i+1,j) , f(v,i+1,j+1));
}


vector<vector<int>>dp;
int fbu(vector<vector<int>>&v ){
    dp.resize(205,vector<int>(205,0));
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if(i==0 and j==0) dp[i][j] = v[i][j];
            else{
                int up = 1e5 , left = 1e5;
                if(j>0) left = v[i][j] + dp[i-1][j-1];
                if(j!=v[i].size()-1) up = v[i][j] + dp[i-1][j];
                dp[i][j] = min(up,left); 
            }
        }
    }
    auto it = min_element(dp[n-1].begin(),dp[n-1].begin()+n);
    return *it;
}


int fbuOpt(vector<vector<int>>&v ){
    vector<int> prev(1);
    int n = v.size();
    for(int i=0;i<n;i++){
        vector<int>temp(i+1,0);
        for(int j=0;j<v[i].size();j++){
            if(i==0 and j==0) temp[j] = v[i][j];
            else{
                int up = 1e5 , left = 1e5;
                if(j>0) left = v[i][j] + prev[j-1];
                if(j!=v[i].size()-1) up = v[i][j] + prev[j];
                temp[j] = min(up,left); 
            }
        }
        prev = temp;
    }
    
    auto it = min_element(prev.begin(),prev.end());
    return *it;
}


int fbuOptO_1(vector<vector<int>>&v ){
    // vector<int> prev(1);
    int n = v.size();
    for(int i=1;i<n;i++){
        // vector<int>temp(i+1,0);
        for(int j=0;j<v[i].size();j++){
            if(j==0){
                v[i][j] += v[i-1][j]; 
            }
            else if(j==v[i].size()-1){
                v[i][j]+=v[i-1][j-1];
            }
            else{
                v[i][j] += min(v[i-1][j],v[i-1][j-1]);
            }
        }
    }
    
    auto it = min_element(v[n-1].begin(),v[n-1].end());
    return *it;
}



int ftd(vector<vector<int>>&v ,int i,int j){
    if(i==v.size()-1){
        cout<<"hit "<<v[i][j]<<endl;
        return v[i][j];
    }
    if(i>=v.size() || j>=v[i].size()) return 1e5;
    if(dp[i][j]!=-1 ) return dp[i][j];

    return dp[i][j] = min(v[i][j] + ftd(v,i+1,j) , v[i][j] + ftd(v,i+1,j+1));
}


int main(){

    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int m;
        cout<<"Enter: ";
        cin>>m;
        vector<int>a(m);
        for(int j=0;j<m;j++){
            cin>>a[j];
        }
        v.push_back(a);
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<"  ";
    //     }cout<<endl;
       
    // }

    // dp.resize(205,vector<int>(205,-1));
    // cout<<ftd(v,0,0);

    cout<<f(v,0,0)<<endl;
    cout<<fbu(v)<<endl;
    cout<<fbuOpt(v);


    return 0;
}
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
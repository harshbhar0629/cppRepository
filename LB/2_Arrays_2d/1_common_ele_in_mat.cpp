#include <bits/stdc++.h>
using namespace std;

void common_ele(vector<vector<int>>&mat){
    
    int n = mat.size();
    int m = mat[0].size();    

    unordered_map<int,int>mp;
    for(int j=0; j<m; j++){
        mp[mat[0][j]] = 1;
    }

    
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(mp[mat[i][j]] == i){
                mp[mat[i][j]] = i+1;
                if(i == n-1) cout<<mat[i][j]<<" ";
            }
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>mat(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }      

    common_ele(mat);

    return 0;
}
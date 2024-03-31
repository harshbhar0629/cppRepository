#include <bits/stdc++.h>
using namespace std;


#define pp pair<int,pair<int,int>>
int findOccurrence(vector<string>& mat, string target){
        
    int n = mat.size();
    int m = mat[0].size();
    queue<pp>qu;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == target[0]){
                qu.push({i,{j,1}});
            }
        }
    }
    
    vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1,0},{0,-1}};
    int count=0;
    
    while(!qu.empty()){
        auto curr = qu.front();
        qu.pop();
        int mi = curr.first;
        int mj = curr.second.first;
        int idx = curr.second.second;
        
        for(int d=0; d<4; d++){
            int ni = mi+dir[d].first;
            int nj = mj+dir[d].second;
            //check for valid index
            if(ni<0 || ni>=n || nj<0 || nj>=m ) continue;
            if(idx==target.size()) {
                count++;
                break;
            }
            if(mat[ni][nj]!=target[idx]) continue;
            qu.push({ni,{nj,idx+1}});
        }
    }
    return count;
}

#define pp pair<int,pair<int,int>>
class Solution{
    
    int f(vector<vector<char> > &mat, string& target, int i, int j,int idx){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]!=target[idx]) return 0;
        int found = 0;
        mat[i][j] = '#';
        if(idx==target.size()-1) found=1;
        else{
            found += f(mat, target, i+1, j, idx+1);
            found += f(mat, target, i, j+1, idx+1);
            found += f(mat, target, i-1, j, idx+1);
            found += f(mat, target, i, j-1, idx+1);
        }
        mat[i][j] = target[idx];
        return found;
    }
    
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        int n = mat.size();
        int m = mat[0].size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == target[0]){
                    cnt+=f(mat, target, i, j, 0);
                }
            }
        }
        
        return cnt;
    }
};


int main(){
    

    return 0;
}
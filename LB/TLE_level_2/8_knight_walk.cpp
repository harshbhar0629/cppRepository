#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/knight-walk4521/1

class Solution {
        
int dir[8][2] = {{-2,-1}, {-1,-2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    
public:
	int minStepToReachTarget(vector<int>&pos, vector<int>&target, int n){
	    queue<pair<int,int>>q;
	    q.push({pos[0],pos[1]});
	    int dis[1005][1005];
	    memset(dis, -1, sizeof dis);
	    dis[pos[0]][pos[1]] = 0;
	    
	    while(!q.empty()){
	        auto curr = q.front();
	        q.pop();
	        int r = curr.first;
	        int c = curr.second;
            if(r == target[0] and c == target[1]){
	            return dis[r][c];
	        }
	        for(int i=0; i<8; i++){
	            int nr = r + dir[i][0];
	            int nc = c + dir[i][1];
	        
	            if(nr<0 || nc<0 || nr>n || nc>n || dis[nr][nc]!=-1){
	                continue;
	            }
	            
	            q.push({nr,nc});
	            dis[nr][nc] = 1+ dis[r][c];
	            if(nr == target[0] and nc == target[1]){
	                return dis[nr][nc];
	            }
	        }
	    }
	    return dis[target[0]][target[1]];
	}
};


int main(){
   


    return 0;
}
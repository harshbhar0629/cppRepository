// https://www.codingninjas.com/studio/problems/walls-and-gates_1092887?leftPanelTab=1
#include <bits/stdc++.h>
using namespace std;



void wallsAndGates(vector<vector<int>> &rooms){
    
    int n = rooms.size();
    int m = rooms[0].size();
    queue<pair<int,int>> q;
    // vector<vector<int>>dis(n,vector<int>(m,-1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(rooms[i][j]==0){
                q.push({i,j});
                // dis[i][j]=0;
            }
        }
    }

    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty()){
        auto cell = q.front();
        q.pop();
        int r = cell.first;
        int c = cell.second;
        for(int k=0; k<4; k++){
            int i = r+dir[k].first;
            int j = c+dir[k].second;

            if(i<0 || j<0 || j>=m || i>=n) continue;
            if(rooms[i][j]!=INT_MAX) continue;
            q.push({i,j});
            rooms[i][j] = 1+rooms[r][c];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<rooms[i][j]<<" ";
        }cout<<endl;
    }

}

int main(){
    int n,m ;
    cin>>n>>m;

    vector<vector<int>>rooms(n,vector<int>(m));
    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            cin>>rooms[i][j];
        }
    }

    wallsAndGates(rooms);


    return 0;
}

// 4
// 4
// 2147483647 -1 0 2147483647
// 2147483647 2147483647 2147483647 -1           
// 2147483647 -1 2147483647 -1
// 0 -1 2147483647 2147483647

// [2147483647,-1,0,2147483647],
// [2147483647,2147483647,2147483647,-1],
// [2147483647,-1,2147483647,-1],
// [0,-1,2147483647,2147483647]

// Explanation:
// the 2D grid is:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// the answer is:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4


// void wallsAndGates(vector<vector<int>> &rooms){
//     int n = rooms.size();
//     int m = rooms[0].size();
//     queue<pair<int,int>>q;
//     for(int i=0; i<n ;i++){
//         for(int j=0; j<m ;j++){
//             if(rooms[i][j] == 0){
//                 q.push({i,j});
//             }
//         }
//     }   

//     vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0},{-1,0}};

//     while(!q.empty()){
//         auto curr = q.front();
//         q.pop();
//         int r = curr.first;
//         int c = curr.second;
//         for(int d=0; d<4; d++){
//             // new row
//             int i = r+ dir[d].first;
//             // new col
//             int j = c+ dir[d].second;
//             if(i<0 || j<0 || i>=n || j>=m) continue;
//             if(rooms[i][j]!=INT_MAX) continue;
//             q.push(i,j);
//             rooms[i][j] = 1+ room[r][c];
//         }
//     }
// }
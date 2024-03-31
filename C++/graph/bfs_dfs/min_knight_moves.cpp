// https://www.codingninjas.com/studio/problems/minimum-knight-moves_2179628
#include <bits/stdc++.h>
using namespace std;


// int minKnightMoves(int x, int y){

//     queue<pair<int,pair<int,int>>> qu;
//     set<pair<int,int>>s;
//     qu.push({0,{0,0}});
//     s.insert({0,0});
//     vector<pair<int,int>> dir = {{-2,-1},{-2,1},{-1,-2},{-1,2}, {1,-2},{1,2},{2,-1},{2,1}};

//     while(not qu.empty()){
//         int r = qu.front().first;
//         int c = qu.front().second.first;
//         int step = qu.front().second.second;
//         qu.pop();
//         if(r==x and c==y) return step;
//         for(int k=0; k<8; k++){
//             int i = r+dir[k].first;
//             int j = c+dir[k].second;
//             if(i+j > 300 || i<-1 || j<-1 || s.count({i,j})) continue;
//             s.insert({i,j});
//             qu.push({i,{j,step+1}});
//         }
//     }
//     return -1;
// }

int minKnightMoves(int ,int);
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        cout<<"Ans->> "<<minKnightMoves(x,y)<<"\n";
    }
 
    return 0;
}

int minKnightMoves(int x,int y){

    x = abs(x);
    y = abs(y);
    queue<pair<int,pair<int,int> > > q;
    set<pair<int,int>>s;

    vector<pair<int,int>> dir = {{-2,-1}, {-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    q.push({0,{0,0}});
    s.insert({0,0});

    while(not q.empty()){
        auto curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second.first;
        int step = curr.second.second;
        if(r==x and c==y) return step;

        for(int d=0; d<8; d++){
            int i = r+dir[d].first;
            int j = c+dir[d].second;
            if(i<-1 || j<-1 || i>=102 || j>=102) continue;
            if(s.count({i,j})) continue;
            // if(r==i and c==j) return step+1;
            q.push({i,{j,step+1}});
            s.insert({i,j});
        }

    }
    return -1;
}
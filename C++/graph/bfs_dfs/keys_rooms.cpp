// https://leetcode.com/problems/keys-and-rooms/description/
#include <bits/stdc++.h>
using namespace std;


bool canVisitAllRooms(vector<vector<int>>&rooms){
    
    int n = rooms.size();
    queue<int>qu;
    unordered_set<int>mp;

    for(int i=0; i<rooms[0].size(); i++){
        int x = rooms[0][i];
        if(x>0){
            qu.push(x);
            mp.insert(x);
        }
    }

    while(not qu.empty()){
        int idx = qu.front();
        qu.pop();
        for(int j=0; j<rooms[idx].size(); j++){
            int x = rooms[idx][j];
            if(x>0 and not mp.count(x)){
                mp.insert(x);
                qu.push(x);
            }
        }
        if(mp.size()==n-1) return true;
    }

    return false;

}


int main(){
    

    return 0;
}
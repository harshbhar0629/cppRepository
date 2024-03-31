// https://leetcode.com/problems/number-of-provinces/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    // store group
    vector<int> parent;

    // it helps to find its leader or parent
    int find(int x){
        if(parent[x]==-1) return x;
        return parent[x] = find(parent[x]);
    }

    // it helps to make union
    void _union(int a , int b){
        a = find(a);
        b = find(b);

        if(a==b) return ;
        parent[a] = b;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        ios_base::sync_with_stdio(NULL);
        cin.tie(0);
        cout.tie(0);

        int n = isConnected.size();
        parent.resize(n,-1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j]){
                    _union(i, j);
                }
            }
        }

        int count =0 ;
        for(int i=0; i<n ;i++){
            if(parent[i]==-1) count++;
        }

        return count;
    }
};


int main(){
    

    return 0;
}
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
#include <bits/stdc++.h>
using namespace std;

// obs: this pattern wants to connect all computer direct or indirect no matter but want connected 
// if cabels are lesser then n-1 then simply return -1 o/w try to connect all computer 
// if count == 0 means all cabel are connected to our computer then simply return 0  
class Solution {

    int find(int x, int *par){
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }

    // void _union(int a, int b, vector<int>&par){
    //     a = find(a, par);
    //     b = find(b, par);
    //     if(a==b) return ;
    //     par[a] = b;
    // }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()+1 < n) return -1;

        int par[n];
        for(int i=0; i<n; i++) par[i] = i;
        int count = n;
        // iota(par.begin(), par.end(), 0);

        for(auto it: connections){
            int a = it[0];
            int b = it[1];
            a = find(a, par);
            b = find(b, par);
            if(a==b) continue;
            par[a] = b;
            count--; 
            // _union(it[0], it[1], par);
        }

        // int count=-1;

        // for(int i=0; i<n; i++){
        //     if(par[i]==i){
        //         count++;
        //     }
        // }
        if(count-1<0) return 0;
        return count-1;
    }
};

int main(){
    

    return 0;
}
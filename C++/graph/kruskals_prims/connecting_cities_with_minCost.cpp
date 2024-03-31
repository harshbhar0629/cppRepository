// https://leetcode.ca/all/1135.html
#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& p, int x){
    if(x==p[x]) return x;
    return p[x] = find(p, p[x]);
}

int minimumCost(int n, vector<vector<int>>& connections){
// connections.
    vector<int>par(n+1);
    iota(par.begin(), par.end(),0);
    sort(connections.begin(), connections.end(), [](auto& a, auto& b) { return a[2] < b[2]; });

    int ans=0;

    for(auto curr: connections){
        int a = curr[0];
        int b = curr[1];
        int wt = curr[2];
       
        a = find(par,a);
        b = find(par,b);
        if(a==b) continue;

        par[find(par, a)] = find(par,b);
        ans+=wt;
        if(--n==1) return ans;
    }

    return -1;
}


int main(){
    

    return 0;
}
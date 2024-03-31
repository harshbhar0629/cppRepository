#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1


bool isSafe(int src, int col, int n, int color[], bool graph[101][101]){
    for(int i=0; i<n; i++){
        if(i!=src and color[i]!=col and graph[src][i]==1){
            return 0;
        }
    }
    return 1;
}


bool solve(int src, int m,int n, int color[], bool graph[101][101]){
    if(src==n){
        return 1;
    }
    for(int i=1; i<=m; i++){
        if(isSafe(src, i, n, color, graph)){
            color[src] = i;
            if(solve(src+1, m, n, color, graph)){
                return 1;
            }
        }
    }
    return 0;
}


bool graphColoring(bool graph[101][101], int m, int n){
    int color[n] = {0};
    if(solve(0, m, n, color, graph)){
        return 1;
    }
    return 0;
}


int main(){
    

    return 0;
}
// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,pair<int,int>>
int MAX = 5;

int kthSmallest(vector<vector<int>>&mat, int n, int k){
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    
    for(int i=0; i<n; i++){
        pq.push({mat[i][0] , {i, 0}});
    }

    while(--k){
        auto curr = pq.top();
        pq.pop();
        int val = curr.first;
        int i= curr.second.first;
        int j = curr.second.second;
        if(j+1<n){
            pq.push({mat[i][j+1], {i, j+1}});
        }
    }
    
    return  pq.top().first;
}

int main(){
    

    return 0;
}
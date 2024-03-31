// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;
#define pp pair<int,pair<int,int>>
// first -> element second.first table no. second.second no of times 
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        if(n*m==k) return n*m;
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        for(int i=1 ; i<=m ; i++){
            pq.push({i,{i,1}});
        }

        while(--k){
            auto it = pq.top();
            pq.pop();
            int first = it.second.first;
            int second=it.second.second+1;
            if(second<=n){
                pq.push({first*second , {first,second}});
            }
        }
        return pq.top().first;

    }
};


class Solution {

    int isAnswerPossible(int n ,int m , int mid){
        int sum=0;
        for(int i=1;i<=m;i++){
            sum+=min(n,mid/i);
        }
        return sum;
    }

public:
    int findKthNumber(int m, int n, int k) {

        int lo=0,hi=m*n;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isAnserPossible(n,m,mid)<k){
                lo = mid+1;
            }
            else hi = mid-1;
        } 

    }
};
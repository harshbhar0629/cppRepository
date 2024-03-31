#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    static bool cmp(vector<int> a,vector<int>b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmp);

        int maxProfit =0;
        for(int i=0;i<n;i++){

            if(truckSize==0) break;
            if( boxTypes[i][0] <= truckSize ){
                // add max profit by their pdt 
                maxProfit = maxProfit + boxTypes[i][0]*boxTypes[i][1];
                truckSize-= boxTypes[i][0];
            }
            else{
                maxProfit += boxTypes[i][1]*truckSize;
                truckSize=0;
            }
        }
        return maxProfit;
    }
};

class Solution {
public:

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        priority_queue<pair<int,int>> pq;
        int n = boxTypes.size();

        for(int i=0;i<n;i++){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }

        int maxProfit=0;

        while(pq.size() and truckSize>0){
            auto it = pq.top();
            pq.pop();
            if(it.second<=truckSize){
                maxProfit = maxProfit + it.first*it.second;
                truckSize -=it.second;
            }
            else{
                maxProfit = maxProfit + it.first*truckSize;
                truckSize=0;
            }
        }
        return maxProfit;
    }
};

int main(){
    

}
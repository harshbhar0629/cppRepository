#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto ele: nums){
            if(ele!=0){
                pq.push(ele);
            }
        }
        int count=0;
        while(pq.size()){
            int first = pq.top();
            pq.pop();
            while(!pq.empty() and pq.top()==first ){
                pq.pop();
            }
            count++;
        }
        
        return count;
    }
};

int main(){

    return 0;
}
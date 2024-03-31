#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq(arr.begin(),arr.end());
        while(pq.size()>1){
            int p1 = pq.top();
            pq.pop();
            int p2 = pq.top();
            pq.pop();
            int diff = abs(p1 - p2);
            if(diff != 0){
                pq.push(diff);
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
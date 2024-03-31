#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/task-scheduler/


class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        
        unordered_map<char,int>mp;
        // store freq of character
        for(auto ele: arr){
            mp[ele]++;
        }

        priority_queue<int> pq;
        // add freq in max heap
        for( auto ele: mp){
            pq.push(ele.second);
        }

        int totalTime = 0;
        // count time to perform a task

        while(pq.size()){
            vector<int> v;
            for(int i=0;i<=n;i++){
                if(pq.size()){
                    int freq = pq.top();
                    pq.pop();
                    if(freq > 1) v.push_back(freq-1);
                }
                
                totalTime++;
                if(v.empty() and pq.empty()) return totalTime;
            }

            for(auto it: v){
                pq.push(it);
            }
        }
        return totalTime;
    }
};


/************************************************************************/
class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        
        vector<int>v(26,0);
        int maxFreq=0,countFreq=0;
        int size= arr.size();
       
        for(int i=0;i<size;i++){
            v[arr[i] - 'A']++;
            if(maxFreq < v[arr[i]-'A']){
                maxFreq = v[arr[i]- 'A'];
            }
        }
        for(int i=0;i<26;i++){
            if(v[i] == maxFreq) countFreq++;
        }

        int totalTime = countFreq + (n+1)*(maxFreq-1);
        return max(totalTime,size);      
    }
};

int main()
{

    return 0;
}
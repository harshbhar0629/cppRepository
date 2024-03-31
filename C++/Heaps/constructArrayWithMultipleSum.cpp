// https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC:  O(N^2)
    bool isPossible(vector<int>& target) {

        long sum =0;
        int max=0;
        
        for(int i=0;i<target.size();i++){
            sum += target[i];
            if(target[max]<target[i]){
                max = i;
            }
        }
        
        
        long diff = sum - target[max];
        
        if(target[max] == 1 || diff == 1) return true;

        if(diff>target[max] || diff == 0 || target[max]%diff==0) return false;
        
        target[max] %= diff;
        
        return isPossible(target);  

    }


    // TC: O(nlogn)
    bool isPossibleOptimised(vector<int>& target) {

        priority_queue<int> pq;
        long long sum =0;

        for(int i=0;i<target.size();i++){
            sum+=target[i];
            pq.push(target[i]);
        }

        while(pq.top()!=1){
    
            int top = pq.top();
            pq.pop();
            long long diff = sum - top;
            
            if(diff==1 ) return true;
            if(diff==0 || diff>top || top % diff==0 ) return false;
    
            sum = sum - top + top%diff;
            top = top%diff;
            pq.push(top);
        }
        return true;
    }

};

int main(){

}
// https: // leetcode.com/problems/construct-target-array-with-multiple-sums/solutions/2189359/c-easy-sol-using-priority-queue-beats-100
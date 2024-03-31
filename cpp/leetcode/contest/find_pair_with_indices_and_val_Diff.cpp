// https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/
// https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idxDiff, int valDiff) {
        // vector<int>ans(2,-1);
        // int n = nums.size();
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //  priority_queue<pair<int,int>>pqr;
        // for(int i=idxDiff; i<n; i++){
        //     pq.push({nums[i-idxDiff],i-idxDiff});
        //      pqr.push({nums[i-idxDiff],i-idxDiff});
        //         if(abs(pq.top().first - nums[i]) >= valDiff){
        //             ans[0]=pq.top().second;
        //             ans[1] = i;
        //             return ans;
        //         }
        //     if(abs(pqr.top().first - nums[i]) >= valDiff){
        //             ans[0]=pqr.top().second;
        //             ans[1] = i;
        //             return ans;
        //         }
        // }
        // return ans;

        vector<int>ans(2,-1);
        int n = nums.size();
        int maxi = 0, mini = 1e9, idx1=0, idx2=0;
        
        for(int i=idxDiff; i<n; i++){
            if(maxi<nums[i-idxDiff]){
                maxi = nums[i-idxDiff];
                idx1 = i-idxDiff; 
            }
            if(mini>nums[i-idxDiff]){
                mini = nums[i-idxDiff];
                idx2 = i-idxDiff; 
            }
            if(abs(nums[i]-maxi) >= valDiff){
                return {idx1,i};
            }
            if(abs(nums[i]-mini) >= valDiff){
                return {idx2,i};
            }

        }
        return ans;
    }
};


int main(){

    return 0;
}
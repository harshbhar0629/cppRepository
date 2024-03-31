class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int i=0;
     
        while(k--){
      
            if(nums[i] < 0){
                nums[i]= -nums[i];
                if(i+1 < nums.size() and nums[i]>nums[i+1])
                    i++;
            }
            else{
                if(nums[i]==0){
                    nums[i]=-nums[i];
                }
                else{
                     nums[i]=-nums[i];
                }
            }
        }
        
        int ansSum=0;
        for(int i=0;i<nums.size();i++){
         
            ansSum+=nums[i];
        }
        return ansSum;
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int ansSum=0;

        while(k--){
            int ele = pq.top();
            pq.pop();
            if(ele==0) break;
            ele = -ele;
            pq.push(ele);
        }
      
        while(pq.size()){
            ansSum += pq.top();
            pq.pop();
        }

        return ansSum;
    } 
};
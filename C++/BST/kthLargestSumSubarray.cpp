class Solution{
public:
// TC: O(n^2) and SC: O(k)
    int kthLargest(vector<int> &arr,int n,int k){
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum +=arr[j];
                if(pq.size()<k){
                    pq.push(sum);
                }
                else {
                    if(sum>pq.top()){
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        
        vector<int> ans ;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        k = n-k;
        return ans[k];

    }
};
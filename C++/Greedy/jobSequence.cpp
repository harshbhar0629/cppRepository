// Given a set of N jobs where each jobi has a deadline and profit associated with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
// We earn the profit associated with job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


// Example 1:

// Input:
// N = 4
// Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60
// Explanation:
// Job1 and Job3 can be done with
// maximum profit of 60 (20+40).

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


class Solution {
    public:
    
    static bool cmp(Job a,Job b){
        return a.profit > b.profit;
    } 
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        
        sort(arr,arr+n,cmp);
        int maxSize=INT_MIN;
        for(int i=0;i<n;i++){
            
            maxSize = max(maxSize,arr[i].dead);
        }
        
        vector<int>v(maxSize+1,-1);
        int maxProfit=0, count=0;
        
        for(int i=0;i<n;i++){
            
            int currProfit = arr[i].profit;
            int currId =arr[i].id;
            int currDead = arr[i].dead;
            
            for(int j= currDead; j>0; j--){
               
                if(v[j]==-1){
                    count++;
                    maxProfit += currProfit;
                    v[j] = currId;
                    break;
                }
            }
        }
        
        vector<int> ans(2);
        ans[0]=count;
        ans[1]=maxProfit;
        
        return ans;
        
    } 
};
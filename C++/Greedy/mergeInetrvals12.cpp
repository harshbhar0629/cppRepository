// 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // sort by start time
    vector<vector<int>> mergeVariation1(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            vector<int>& curr = ans.back();
            int x = curr[1];
            if(x>= intervals[i][0]){
                curr[1] = max(x, intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    
    }

    // sort by ending time
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    vector<vector<int>> mergeVariation2(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(intervals[n-1]);

        for(int i= n-2;i>=0;i--){
            int ansFirst = ans.back()[0]; 
            int currEnd = intervals[i][1];

            if(ansFirst <= currEnd){
                int ansEnd = ans.back()[1];
                int currFirst = intervals[i][0];   
                ans.back()[0] = min(ansFirst,currFirst);
                ans.back()[1] = max(ansEnd,currEnd);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }

};


int main(){

   
    return 0;
}
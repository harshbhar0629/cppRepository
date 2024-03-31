#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/merge-intervals/description/

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(intervals[n-1]);

        for(int i=n-2; i>=0; i--){
            if(intervals[i][1] >= ans.back()[0]){
                ans.back()[0] = min(ans.back()[0] , intervals[i][0]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};


class Solution {

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(auto& curr: intervals){
            if(curr[0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1] , curr[1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}
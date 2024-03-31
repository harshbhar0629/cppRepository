// https://leetcode.com/problems/number-of-flowers-in-full-bloom/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n = people.size();
        int m = flowers.size();
        vector<int>bloomTimeStart(m), bloomTimeEnd(m);

        for(int i=0; i<m; i++){
            bloomTimeStart[i] = flowers[i][0];
            bloomTimeEnd[i] = flowers[i][1];
        }

        sort(bloomTimeStart.begin(), bloomTimeStart.end());
        sort(bloomTimeEnd.begin(), bloomTimeEnd.end());

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            auto it = upper_bound(bloomTimeStart.begin(), bloomTimeStart.end(),people[i]) - bloomTimeStart.begin();
            auto itr = lower_bound(bloomTimeEnd.begin(), bloomTimeEnd.end(),people[i]) - bloomTimeEnd.begin();
            ans[i] = it-itr;
        }

        return ans;
    }
};


int main(){
    

    return 0;
}
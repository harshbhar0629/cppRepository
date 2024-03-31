#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        set<int>s;
        int n = nums.size();
        int miniDiff=INT_MAX;

        for(int j=x; j<n; j++){
            s.insert(nums[j-x]);
            auto it = s.lower_bound(nums[j]);
            if(it == s.end()) it--;

            int val = *it;
            miniDiff = min(miniDiff, abs(nums[j]-val));

            if(it==s.begin()) continue;
            it--;
            val = *it;
            miniDiff = min(miniDiff, abs(val-nums[j]));
        }
        return miniDiff;
    }
};


int main(){

    return 0;
}
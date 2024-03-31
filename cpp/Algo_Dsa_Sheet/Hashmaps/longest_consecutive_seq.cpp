#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return n;
        }
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int maxi = 0;
        int num = nums[0];

        for (int i = 0; i < n; i++)
        {
            if (num + 1 == nums[i])
            {
                cnt++;
            }
            else if (num != nums[i])
            {
                maxi = max(maxi, cnt);
                cnt = 1;
            }
            num = nums[i];
        }

        return max(maxi, cnt);
        // int n = nums.size();
        // int maxi = 1;
        // unordered_map<int,int>mp;
        // for(int i=0; i<n; i++) mp[nums[i]]++;

        // for(int i=0; i<n; i++){
        //     if(mp.find(nums[i]-1) == mp.end()){
        //         int num = nums[i];
        //         int cnt = 0;
        //         while(mp.find(num) != mp.end()){
        //             cnt++;
        //             num++;
        //         }
        //         maxi = max(maxi, cnt);
        //     }
        // }
        // return maxi;
    }
};

int main(){
    

    return 0;
}
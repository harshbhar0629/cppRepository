#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution{

    // TC: O(N) SC: O(N)
    vector<int> approach2(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        for (auto &it : nums1)
        {
            mp[it]++;
        }

        vector<int> ans;
        for (auto &it : nums2)
        {
            if (mp[it] > 0)
            {
                ans.push_back(it);
                mp[it]--;
            }
        }

        return ans;
    }

    //  TC: O(NlogN) SC: O(1)
    vector<int> approach1(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;
        vector<int>ans;
        while(i<n and j<m){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++, j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }

        return ans;
    }

public : 
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2){
        // return approach1(nums1, nums2);
        return approach2(nums1, nums2);
    }
};

int main(){
    

    return 0;
}
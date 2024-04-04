#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/next-greater-element-i/description/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();
        int m = nums2.size();
        vector<int> greater(m, -1);
        stack<int> st;
        unordered_map<int, int> mp;
        st.push(0);
        mp[nums2[0]] = 0;

        for (int i = 1; i < m; i++)
        {
            mp[nums2[i]] = i;
            while (!st.empty() and nums2[st.top()] < nums2[i])
            {
                greater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            int idx = mp[nums1[i]];
            nums1[i] = greater[idx];
        }

        return nums1;
    }
};

int main(){

    return 0;
}
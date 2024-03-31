// https://leetcode.com/problems/next-greater-element-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        stack<int>st;
        st.push(0);
        vector<int> ans(n,-1);
        
        for(int i=1; i<n; i++){
            while(!st.empty() and nums[st.top()] < nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0; i<n; i++){
            while(!st.empty() and nums[st.top()] < nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }


    return 0;
}
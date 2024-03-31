// https://leetcode.com/problems/next-greater-element-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for(int i=0; i<n; i++){
            int idx = -1;
            int m = nums2.size();
            for(int j=0; j<m; j++){
                if(nums1[i] == nums2[j]){
                    idx = j;
                    break;
                }
            }
            bool flag = true;
            for(int j=idx+1; j<m; j++){
                if(nums1[i]<nums2[j]){
                    nums1[i] = nums2[j];
                    flag = false;
                    break;
                }
            }
            if(flag){
                nums1[i]=-1;
            }
        }

        return nums1;
    }
};

vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {

    int m = nums2.size();
    int n = nums1.size();
    stack<int>st;
    vector<int>greater(m,-1);
    unordered_map<int,int>mp;
    st.push(0);
    mp[nums2[0]] = 0;

    for(int i=1; i<m; i++){
        mp[nums2[i]] = i;
        while(!st.empty() and nums2[st.top()] < nums2[i]){
            greater[st.top()] = nums2[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0; i<m; i++) cout<<greater[i]<<" ";
    
    for(int i=0; i<n; i++){
        int idx = mp[nums1[i]];
        nums1[i] = greater[idx];
    }
cout<<endl;
    return nums1;
}
// 4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int m;
    cin>>m;
    vector<int>v2(m);
    for(int i=0; i<m; i++){
        cin>>v2[i];
    }
    

    vector<int> ans = nextGreaterElement1(v, v2);

    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}
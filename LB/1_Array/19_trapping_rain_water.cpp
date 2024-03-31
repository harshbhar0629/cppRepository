// https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        
        int n = heights.size();
        int arr[n];
        int left_max = 0;
        for(int i=0; i<n; i++){
            arr[i] = left_max;
            left_max = max(left_max, heights[i]);
        }
        int right_max=0;
        for(int i=n-1; i>=0;  i--){
            arr[i] = right_max;
            right_max = max(right_max, heights[i]);
            if(heights[i]==left_max) break;
        }
        int ans =0;

        for(int i=0; i<n; i++){
            if(heights[i]<arr[i]){
                ans+=arr[i] - heights[i];
            }
        }
        return ans;
        // for(int i=1; i<n-1; i++){
        //     int left_max=0, right_max=0;
        //     for(int j=i; j>=0; j--){
        //         left_max = max(left_max, heights[j]);
        //     }
        //     for(int j=i; j<n; j++){
        //         right_max = max(right_max, heights[j]);
        //     }
        //     ans+=min(left_max, right_max) - heights[i];
        // }
        // return ans;
    }
};

int main(){
    

    return 0;
}
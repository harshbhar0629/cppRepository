#include<bits/stdc++.h>
using namespace std;

int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int xo = nums[i];
            ans += xo^0;
            for(int j = i;j<n;j++){
                int x = xo^nums[j];
                ans += x;
            }
        }
        return ans; 
}

int main(){
    vector<int>v(3);
    v[0]=5;
    v[1]=1;
    v[2]=6;
    cout<<(subsetXORSum(v));
    return 0;
}
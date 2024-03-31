#include<bits/stdc++.h>
using namespace std; 
 
 void max_strength(vector<int>& nums,long long strength1,long long strength2,long long &ans,int i){
        if(nums.size()==i){
            return;
        }
        if(nums[i]<0){
            swap(strength1,strength2);
        }
        strength1=max(strength1,strength1*(long long)nums[i]);
        strength2=min(strength2,strength2*(long long)nums[i]);
        ans=max(strength1,strength2);
        max_strength(nums,strength1,strength2,ans,i+1);
    }

    long long maxStrength(vector<int>& nums) {
        long long strength1=nums[0],strength2=nums[0];
        long long ans=nums[0];
        max_strength(nums,strength1,strength2,ans,1);
        return ans;
    
    }
    int main(){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
       cout<<  maxStrength(v);
    }
    // put: nums = [3,-1,-5,2,5,-9]
// Output: 1350
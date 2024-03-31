// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n){
        
        unordered_map<int,int>mp;
        mp[arr[0]]++;
        for(int i=1; i<n; i++){
            arr[i]+=arr[i-1];
            if(arr[i]==0 || mp[arr[i]]>0) return true;
            mp[arr[i]]++;
        }
        return false;
    }
};

int main(){
  

    return 0;
}
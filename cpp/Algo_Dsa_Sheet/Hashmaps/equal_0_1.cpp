#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1

#define ll long long int
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    ll countSubarrWithEqualZeroAndOne(int arr[], int n){
        unordered_map<int,int>mp;
        int sum = 0;
        mp[sum] = 1;
        ll cnt = 0;
        for(int i=0; i<n; i++){
            sum += (arr[i] == 1)? 1: -1;
            cnt += mp[sum];
            mp[sum]++;
        }
        
        return cnt;
    }
};


int main(){
    

    return 0;
}
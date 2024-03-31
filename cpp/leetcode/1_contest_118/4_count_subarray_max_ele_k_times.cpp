#include <bits/stdc++.h>
using namespace std;


#define ll long long int

ll countSubarrays(vector<int>& nums, int k){
    int i = 0, j = 0;
    ll count = 0;
    int freq = 0;
    int maxi = -1;
    int n = nums.size();

    for(int i=0; i<n; i++){
        maxi = max(maxi, nums[i]);
    }

    // algo
    while(i<n){
        if(nums[i] == maxi) freq++;
        while(j<n and freq>=k){
            count+=n-i;
            if(nums[i] == maxi) freq--;
            j++;
        }
        i++;
    }

    return count;
}

/**
 *  // int maxi = -1;
    // int n = nums.size();
    // for(int i=0; i<n; i++){
    //     maxi = max(maxi, nums[i]);
    // }
    // cout<<n;
    // int count=0;
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         int f=0;
    //         for(int k=i; k<=j; k++){
    //             if(maxi==nums[k]) f++;
    //         }
    //         if(f>=k) count++;
    //     }
    // }
    // return count;
*/

int main(){
    

    return 0;
}
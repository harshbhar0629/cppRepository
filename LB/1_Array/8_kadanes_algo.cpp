#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long sum=arr[0], maxSum=arr[0];
        
        for(int i=1; i<n; i++){
            if(sum + arr[i] > arr[i]){
                sum+=arr[i];
            }
            else{
                sum = arr[i];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
        
    }
};


int main(){
    

    return 0;
}
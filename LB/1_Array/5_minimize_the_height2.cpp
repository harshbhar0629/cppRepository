// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int mini = arr[0], maxi = arr[n-1];
        int diff = maxi - mini;
        for(int i=1; i<n; i++){
            if(arr[i]>=k){
                maxi = max(arr[n-1]-k , arr[i-1]+k);
                mini = min(arr[0]+k , arr[i]-k);
                diff = min(diff, maxi-mini);
            }
        }
        return diff;
    }
};

int main(){
    

    return 0;
}
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int minJumps(int arr[], int n){
        
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        int maxi = arr[0] ,jump = 1, step = arr[0] ;
        for(int i=1; i<n; i++){
            if(i==n-1) return jump;
            step--;
            maxi = max(maxi, i+arr[i]);
            if(step==0){
                if(i>=maxi) return -1;
                step = maxi-i;
                jump++;
                // maxi=arr[i];
            }
        }
        return jump;
    }
};


int main(){
    

    return 0;
}
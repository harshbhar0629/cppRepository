#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(int nums[],int n, int k) {
        // int n=nums.size();
        double ans=INT_MIN;
        double avg=0;
        int i=0,j=0;
        for(j=0;j<k;j++){
            avg+= nums[j];
        }
        if((avg/k) > ans){
            ans= (avg/k);
        }
        while(j<n){
            avg += nums[j] - nums[i];
            if((avg/k) > ans){
                ans= (avg/k);
            }
            cout<<avg/k<<endl;
            i++,j++;
        }
        return ans;
}
int main(){
    int k=4;
    int arr[]= {1,12,-5,-6,50,3};
    int n=6;
    cout<<findMaxAverage(arr,n,k);
    return 0;
}
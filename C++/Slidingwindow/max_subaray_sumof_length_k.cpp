#include<bits/stdc++.h>
using namespace std;
int main(){
    // Bruete force to find max sum of subbaray of length k... TC = O((n-k)*k)
    // int arr[]={1,5,2,3,4,6,0,8,1,9,2};
    // int n=11;
    // int k=3;
    // int ans=0;
    // for(int i=0;i<=n-k;i++){
    //     int sum=0;
    //     for(int j=i;j<i+k;j++){
    //         sum+=arr[j];
    //     }
    //     if(ans<sum){
    //         ans=sum;
    //     }
    // }
    // cout<<"max sum of subarray of length k is : "<<ans;

    // optimised TC= O(n);
    int arr[]={1,5,2,3,4,6,0,8,1,9,2};
    int n=11;
    int k=3;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int ans=0;
    ans=max(ans,sum);
    int i=0,j=k;
    while(j<n){
        sum+=arr[j]-arr[i];
        i++,j++;
        if(ans<sum){
            ans=sum;
        }
        cout<<j-i<<endl;
    }
    cout<<"maxsum of subarray of length k: "<<ans<<"\n";


    return 0;
}
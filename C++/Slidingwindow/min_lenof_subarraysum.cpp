#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,3,1,2,4,3};
    int n=6;
    int len=INT_MAX;
    int target=7;
    int sum=0;
    // bruete force solution..
    // for(int i=0;i<n;i++){
    //     sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=arr[j];
            
    //         if(target<sum){
    //             break;
    //         }
    //         if(sum==target){
    //             len=max(len,j-i+1);
    //         }
        
        
    //     }
    // }
    // cout<<"min possible length to achive the target is: "<<len;

    // optimised solution
    int i=0,j=0;
    while(j<n){
        sum+=arr[j];
        while(sum>target){
            sum -= arr[i];
            i++;
        }
        if(sum==target){
            len= min(len,j-i+1);
        }
        j++;
    }
    cout<<"min possible length of target : "<<len;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N=1e8;
    long long arr[N];
    long long k=1;
    for(long long i=0;i<N;i++){
        arr[i]=k++;
    }
    long long target,low=0,high=1;
    target =100008;
    while(arr[high]<target){
        low=high;
        high *=2;
    }
    cout<<low<<"   "<<high;
    while(low<=high){
        long long mid=low+ (high-low)/2;
        if(arr[mid]==target){
            cout<<endl<<mid;
            return 0;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else high=mid-1;
    }


    return 0;
}
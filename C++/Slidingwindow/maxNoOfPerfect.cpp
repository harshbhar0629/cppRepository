#include<bits/stdc++.h>
using namespace std;

bool isPerfect(int n){
    int result=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            if(i==n/i){
                result += i;
            }
            else{
                result += i + n/i ;
            }
        }
    }
    return n!=1 and n==result;
}

int maxSum(int arr[],int n ,int k){
    int res=0,sum=0;
    for(int i=0;i<k;i++){
        res += arr[i];
    }
    sum=res;
    for(int j=k;j<n;j++){
        sum += arr[j] -arr[j-k];
        res = max(res,sum);
    }
    return res;
}

int MaxPerfect(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(isPerfect(arr[i])){
            cout<<arr[i]<<endl;
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }
    return maxSum(arr,n,k);
}

int main(){
    int arr[]= {6,9,43,45,42,52,345,232,34,32,235};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=n-1;

    cout<<MaxPerfect(arr,n,k);
}
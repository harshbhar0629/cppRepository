#include<bits/stdc++.h>
using namespace std;
void f(int arr[],int n,int i,int &ans){
    if(i==n) return ;
    if(ans>arr[i]){
        ans=arr[i];
    }
    f(arr,n,i+1,ans);
}
int main(){
    int arr[]={0,2,3,4,5,6,1,80,2};
    int n=9;
    int ans=INT_MAX;
    f(arr,n,0,ans);
    cout<<ans;
}
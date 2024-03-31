#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>i[arr];
    }
    int i=0,j=1;
    while(j<n){
        if(arr[j]==0){
            j++;
        }
        else if(arr[i]!=0){
            i++;
        }
        else{
            int t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }
    for(int i=0;i<n;i++){
        cout<<i[arr];
    }
    return 0;
}
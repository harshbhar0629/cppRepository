#include<iostream>
using namespace std;
int check(int arr[],int i, int j, int x){
    if(arr[i]==x) return 1;
    if(i==j) return 0;
    check(arr,i+1,j,x);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"enter target";
    cin>>target;
    if(check(arr,0,n,target)){\
        cout<<"yes present";
    }
    else cout<<"not present";
}

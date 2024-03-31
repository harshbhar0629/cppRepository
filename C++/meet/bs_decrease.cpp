#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
     int arr[n];
    for(int i=0;i<n;i++){
        cin>>i[arr];
    }
    int target;
    cout<<"target";
    cin>>target;
    bool flag=true;
    int low=0;int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target) low=mid+1;
        else if(arr[mid]==target) {
            flag=false;
            cout<<"found at index"<<mid;
            break;
        }
        else high=mid-1;
    }
    if(flag) cout<<"not found";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m=INT_MAX;
    for(int i=0;i<n;i++){
        arr[i]=abs(arr[i]);
        // m=min(arr[i],m);
    }
    vector<int>v;
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]<arr[j]){
            v.push_back(arr[j]);
            j--;
        }
        else {
            v.push_back(arr[i]);
            i++;
        }
    }
    for(int i=0,j=v.size()-1;i<=j;i++,j--){
            swap(v[i],v[j]);        
    }
    for(int i=0;i<n;i++){
        cout<<v[i]*v[i]<<"   ";
    }
}
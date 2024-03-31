#include<bits/stdc++.h>
#include<vector>

using namespace std;

void f(int arr[],int n,int i,vector<int>v,bool flag){
    if(i==n){
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }cout<<endl;
        return;
    }
    if(arr[i]==arr[i-1]){
        f(arr,n,i+1,v,flag);
        v.push_back(arr[i]);
        if(flag)
        f(arr,n,i+1,v,0);
    }
    else {
          f(arr,n,i+1,v,flag);
        v.push_back(arr[i]);
        f(arr,n,i+1,v,flag);
    }
   
}
int main(){
        int arr[]={1,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    f(arr,n,0,v,1);
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min_ele(vector<int>&v){
    if(v.size()==1) return v[0];
    
    int low=0;
    int high=v.size()-1;
    if(v[low]<v[high]) return v[0];

    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]>v[mid+1]){
            return v[mid+1];
        }
        if(v[mid]<v[mid-1])
        return v[mid];

        if(v[mid]>v[low]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<min_ele(v);
}
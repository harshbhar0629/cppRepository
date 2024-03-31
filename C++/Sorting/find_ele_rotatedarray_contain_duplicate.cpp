#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&v,int x){
    if(v.size()==1){
        if(v[0]==x){
            return 0;
        }
        else{
            return -1;
        }
    }
    int low=0,high=v.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==x) return mid;
        else if(arr[low] == arr[mid] and arr[mid]==arr[high]){
            low++,high--;
        }
        else if(v[mid]>v[low]){
            if(v[mid]>=x && v[low]<=x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(v[mid]<=x && x<=v[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
        }
    }


    return -1;
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
    int target ;
    cin>>target;
    cout<< f(v ,target);
}
// 4566701244
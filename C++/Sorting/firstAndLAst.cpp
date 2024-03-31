#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&arr,int target){
    int i=-1;
    int low=0;
    int high=arr.size()-1;
   // if(high==1 && arr[high]!=target) return 0;
    while(low<=high){
        int mid=low+(high-low)/2;
        // if(arr[mid]==target){
        //     high=mid-1;
        //     i=mid;
        // }
        // else 
        if(arr[mid]>=target){
            high=mid-1;
            i=mid;
        }
        else{
            low=mid+1;
        }

    }
    return i;
}

int l(vector<int> &arr,int target){
    int i=-1;
    int low=0;
    int high=arr.size()-1;
   // if(high==1 && arr[high]!=target) return 0;
    while(low<=high){
        int mid=low+(high-low)/2;
        // if(arr[mid]==target){
        //     high=mid-1;
        //     i=mid;
        // }
        // else 
        if(arr[mid]<=target){
            low=mid+1;
            i=mid;
        }
        else{
            high=mid-1;
        }

    }

    return i;
}

int main(){
    int n;
    cout<<"entet size";
    cin>>n;
    vector<int>arr;  
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cout<<"target";
    cin>>target;
     vector<int>v;
    int i=f(arr,target);
    if(arr[i]!=target){
        v.push_back(-1);
        v.push_back(-1);
    }
    else{
        int j=l(arr,target);
        v.push_back(i);
        v.push_back(j);
    }
 
    cout<<endl<<v[0]<<"  "<<v[1];
    return 0;
}
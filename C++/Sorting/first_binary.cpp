#include<bits/stdc++.h>
using namespace std;
int f(int arr[],int n,int target){
    int i=-1;
    int low=0;
    int high=n;
   // if(high==1 && arr[high]!=target) return 0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            high=mid-1;
            i=mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }

    return i;
}

int l(int arr[],int n,int target){
    int i=-1;
    int low=0;
    int high=n;
   // if(high==1 && arr[high]!=target) return 0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<=target){
            low=mid+1;
            i=mid;
        }else{
                high=mid-1;
        }

    }

    return i;
}

int main(){
    int n;
    cout<<"entet size";
    cin>>n;
    int arr[n];
    for(int &i : arr){
        cin>>i;
    }
    int target;
    cout<<"target";
    cin>>target;
    cout<<endl<<l(arr,n-1,target);

    return 0;
}
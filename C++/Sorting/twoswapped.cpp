#include<bits/stdc++.h>
using  namespace std;

int main(){
    int arr[]={1,2,8,5,6,7,4};
    int n=7;
    int idx1,idx2;
    bool flag=true;
    int i=0,j=n-1;
    while(i<=j){
        if(flag){
            if(arr[i]>arr[i+1]){
                idx1=i;
                flag=false;
            }
            i++;
        }
        else {
                if(arr[j]<arr[j-1]){
                    idx2=j;
                    break;
                }
                j--;
        }
    }
    swap(arr[idx1],arr[idx2]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}
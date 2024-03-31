#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    cout<<"enter element";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int idx=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        for(int i=0,j=n-1;i<j;i++,j--){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<"  ";
        }
        return 0;
    }
    int midx=-1;
    for(int i=idx+1,j=n-1;i<j;i++,j--){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    for(int i=idx+1;i<n;i++){
        if(arr[idx]<arr[i]){
            midx=i;
            break;
        }
    }
    int temp=arr[idx];
    arr[idx]=arr[midx];
    arr[midx]=temp;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"   ";
    }


    return 0;
}
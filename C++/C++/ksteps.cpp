#include<iostream>
using namespace std;
void reverse(int arr[],int n,int m){
    for(int i=n,j=m-1;i<j;i++,j--){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp ;    
    }
}
int main(){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     int k;
     cout<<"enter k steps";
     cin >>k;
     reverse(arr,0,n);
     reverse(arr,0,k);
     reverse(arr,k,n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
     }
    
    return 0;
}
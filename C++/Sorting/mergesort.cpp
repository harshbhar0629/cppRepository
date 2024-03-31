#include<bits/stdc++.h>
#include<vector>
using namespace std;
// #define int count=0;
// void mergeall(int arr[],int f,int mid,int l){
//     int n=mid-f+1;
//     int m=l-mid;
//     int a[n];
//     int b[m];
//     for(int i=0;i<n;i++){
//         a[i]=arr[f+i];
//     }
//     for(int j=0;j<m;j++){
//         b[j]=arr[1+mid+j];
//     }
//     int i=0,j=0,k=f;
//     while(i<n && j<m){
//         if(a[i]>b[j]){
//             arr[k]=b[j];
//             j++,k++;
//         }
//         else {
//             arr[k]=a[i];
//             i++,k++;
//         }
//     }
//     if(i<n){
//         while(i<n){
//             arr[k]=a[i];
//             k++,i++;
//         }
//     } 
//     else {
//         while(j<m){
//             arr[k]=b[j];
//             k++,j++;
//         }
//     }
// }

void mergeAll(int arr[],int f,int mid,int e){
    int n = mid +1 - f;
    int m = e - mid;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++){
        a[i] = arr[f+i];
    }
    for(int j=0;j<m;j++){
        b[j] = arr[mid+1+j];
    }
    int k =f,i=0,j=0;
    while(i<n and j<m){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] =b[j++];
        }
    }
    while(i<n){
        arr[k++] = a[i++];
    }
    while(j<m){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[],int i,int n){
  if(i<n){
    int mid=(i+n)/2;
    mergeSort(arr,i,mid);
    mergeSort(arr,mid+1,n);
    mergeAll(arr,i,mid,n);
  }
}

int main(){
    int arr[]={8,7,6,5,4,3,2,1};
    int n=8;
    // vector<int> v(arr,arr+n);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

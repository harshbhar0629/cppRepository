#include<bits/stdc++.h>
#include<vector>
using namespace std;
// int partition(int arr[],int si,int ei){
//     int ele=arr[si];
//     int count=0;
//     for(int i=si+1;i<=ei;i++){
//         if(ele>=arr[i]){
//             count++;
//         }
//     }
//     int pivot=count+si;
//     int i=si,j=ei;
//     swap(arr[si],arr[pivot]);
//     while(i<pivot && j>pivot){
//         if(arr[i]<=ele) i++;
//         else if(arr[j]>ele) j--;
//         else{
//             swap(arr[i],arr[j]);
//             i++,j--;
//         }
//     }
//     return pivot;

// }

int partition(int arr[],int si,int ei){
    int ele = arr[si];
    int count=0;
    for(int i=si+1;i<=ei;i++){
        if(ele >= arr[i]) count++;
    }
    int pivot = si+count;
    int i=si ,j= ei;
    swap(arr[si],arr[pivot]);
    while( i < pivot and pivot<j){
        if(arr[i] <= ele) i++;
        else if(arr[j] > ele) j--;
        else{
            swap(arr[i],arr[j]);
            i++,j--;
        }
    }
    return pivot;
}

void quicksort(int arr[],int si,int ei){
    if(si<ei){
        int pivot=partition(arr,si,ei);
        quicksort(arr,si,pivot-1);
        quicksort(arr,pivot+1,ei);

    }
}

int main(){
    int arr[]={2,3,1,7,8,9,6,4,5};
    int n=9;
    quicksort(arr,0,n-1);
    
    for(int i=0;i<9;i++){
        cout<<arr[i]<<"  ";
    }
}

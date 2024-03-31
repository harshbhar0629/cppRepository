#include<iostream>
using  namespace std;
int partition(int arr[],int si,int ei){
    int ele=arr[(si+ei)/2];
    int count=0;
    for(int i=si;i<=ei;i++){
        if(arr[i]<= ele && i!=(si+ei)/2){
            count++;
        }
    }
     int pivot=count+si;
    swap(arr[(ei+si)/2],arr[pivot]);
    int i=si,j=ei;
   
    while(i<count &&j>count){
        if(arr[i]<=ele) i++;
        else if(arr[j]>ele) j--;
        else{
            swap(arr[i],arr[j]);
            i++,j--;
        }
    }
    return pivot;
}
int kthsmall(int arr[],int si,int ei,int k){
   
        int pivot=partition(arr,si,ei);
        if(k==pivot+1) return arr[pivot];
        if(pivot+1<k){
            return kthsmall(arr,pivot+1,ei,k);
        }
        else{
            return kthsmall(arr,si,pivot-1,k);
        }
    
}
int main(){
    int arr[]={1,3,5,7,9,2,4,6,8};
    int n=9;
    int k=9;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
    cout<<kthsmall(arr,0,n-1,k);
}
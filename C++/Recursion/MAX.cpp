#include<bits/stdc++.h>
using namespace std;
void f(int arr[],int n,int i,int max){
    if(i==n){
        cout<<endl<<max<<endl;
        return;
    }
    if(arr[i]>max) max=arr[i];
    f(arr,n,i+1,max);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int n=10;
    f(arr,n,0,INT_MIN);
}
#include<bits/stdc++.h>
using namespace std;
void f(int arr[],int n){
    if(n==0) return;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }
    f(arr,n-1);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>i[arr];
    }
    cout<<endl;
    f(arr,n-1);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
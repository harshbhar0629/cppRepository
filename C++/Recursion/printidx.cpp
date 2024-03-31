#include<bits/stdc++.h>
using namespace std;
int f(int arr[],int n,int target){
   
    if(n<0) return 0;

    if(arr[n]==target) return n;

    return f(arr,n-1,target);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>i[arr];
    }
    int target ;
    cin>>target;
    cout<<f(arr,n-1,target);
}
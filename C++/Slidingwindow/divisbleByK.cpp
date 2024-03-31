#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int rem=0;
    int k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;

    for(int i=0;i<k;i++){
        rem = rem + arr[i];
        rem = rem%3;
    }
    if(rem == 0){
        cout<<"starting index = 0 of size "<<k<<endl;
        return 0;
    }
    int i=0,j=k;
    while(j<n){
        rem -= arr[i]%3;
        rem += arr[j]%3;
        if(rem == 0){
            cout<<"strating index start from "<<i<<endl;
            return 0;
        }
        i++;
        j++;
    }
    
    cout<<"no such group present which is divisible by 3"<<endl;


}
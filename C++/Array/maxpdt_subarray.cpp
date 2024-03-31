#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int ans=arr[0];
    int mi=ans,mx=ans;
    for(int i=1;i<n;i++){
        if(arr[i]<0){
            swap(mi,mx);
        }
        mx=max(arr[i]*mx,arr[i]);
        mi=min(arr[i],mi*arr[i]);
        ans=max(ans,mx);
    }
    cout<<mi<<endl<<ans;

}
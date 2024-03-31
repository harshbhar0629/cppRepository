#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,1,1,0,0,0,1,1,1,1,0};
    int n=11;
    int k=2;
    int count=0,maxlen=INT_MIN,i=0,j=0;
    while(j<n){
        if(arr[j]==0 && count<=k){
            count++;
        }
        while(count>k){
            if(arr[i]==0)
                count--;
                i++;
        }
        maxlen=max(maxlen,j-i+1);
        j++;
    }
    cout<<maxlen;

    return 0;
}
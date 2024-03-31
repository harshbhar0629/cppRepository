#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,5,3,9,1,5,3,3,5,1};
    int n=10;
    vector<int>v(32,0);
    for(int i=0;i<n;i++){
        int curr=0;
        while(arr[i]){
            if((arr[i]&1)>0){
                v[curr]++;
            }
            curr++;
            arr[i]=arr[i]>>1;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
    int duplicate=0;
    for(int i=0;i<32;i++){
        duplicate += ((v[i]%3)<<i);
    }
    cout<<endl<<"duplicate is"<<duplicate;
    return 0;
}
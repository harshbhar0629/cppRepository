#include<bits/stdc++.h>
using namespace std;
// print and store onlyyyyyyyy.....
void f1(int arr[] ,int i,int n,vector<int>v,bool flag ){

    if(i==n){
        for(int j=0;j<v.size();j++){
            cout<<v[j];
        }cout<<endl;
        return;
    }
    if(i==n-1){
         
        f1(arr,i+1,n,v,true);
        v.push_back(arr[i]);
        if(flag) {
            f1(arr,i+1,n,v,true);
        }
        return;
    }

    else if(arr[i]==arr[i+1]){
         
        f1(arr,i+1,n,v,false);
        v.push_back(arr[i]);
        if(flag){
            f1(arr,i+1,n,v,true);
        }
    }
    else{ 
        
        f1(arr,i+1,n,v,true);
        v.push_back(arr[i]);
        if(flag) {
            f1(arr,i+1,n,v,true);
        }
    }
}

int main(){
    int arr[]={1,1,2};
    vector<int>v;
    // vector<vector<int>>ans;
    int n=3;
    f1(arr,0,n,v,true);

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<endl;
    // }

} 
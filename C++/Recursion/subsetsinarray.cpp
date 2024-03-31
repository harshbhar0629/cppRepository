#include<bits/stdc++.h>
using namespace std;
// print onlyyyyyyyy.....
void f1(int arr[], int n,int i,vector<int> ans){
    
    if(i==n){
        for(int j=0;j<ans.size();j++){
            cout<<ans[j];
        }cout<<endl;
       
        return;
    }
    
    f1(arr,n,i+1,ans);
    ans.push_back(arr[i]);
    f1(arr,n,i+1,ans);

}



int main(){
    int arr[]={1,2,3};
    int n=3;
    // f1(s,"",0);
   vector<int>v;
   f1(arr,n,0,v);
   
   
    // vector<string>v;
    // f2(s,"",0,v);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<endl;
    // }

}
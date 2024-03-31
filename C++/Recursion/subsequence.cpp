#include<bits/stdc++.h>
using namespace std;
// print onlyyyyyyyy.....
void f1(int arr[], int n,int i,vector<int> ans,int k){
    
    if(i==n){

        if(ans.size()==k){
            for(int j=0;j<ans.size();j++){
                cout<<ans[j];
            }cout<<endl;
        }

        return;
    }
    if(ans.size()+(n-i)<k) return;
    f1(arr,n,i+1,ans,k);
    ans.push_back(arr[i]);
    f1(arr,n,i+1,ans,k);

}



int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
   int k=3;
   vector<int>v;
   f1(arr,n,0,v,k);
   
   
   

}
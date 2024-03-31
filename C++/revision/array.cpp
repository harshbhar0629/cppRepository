#include<bits/stdc++.h>
using namespace std;
// void f(int arr[],int n, int i,vector<int>v,bool flag){
//     if(i==n){
//         for(int i=0;i<v.size();i++){
//             cout<<v[i]<<" ";
//         }cout<<endl;
//         return;
//     }
//     if(i==n-1){
//       f(arr,n,i+1,v,true);
//          v.push_back(arr[i]);
      
//          if(flag){
//             f(arr,n,i+1,v,true);
//         }
//         return;
//     }
//     if(arr[i]==arr[i+1]){
//           f(arr,n,i+1,v,0);
//          v.push_back(arr[i]);
      
//          if(flag){
//             f(arr,n,i+1,v,1);
//         }

//     }
//     else{
//            f(arr,n,i+1,v,true);
//          v.push_back(arr[i]);
      
//          if(flag){
//             f(arr,n,i+1,v,true);
//         }
//     }
    
// }
void f(int arr[],int n, int i,vector<int>v,int k){
    if(i==n){
        if(v.size()==k){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    f(arr,n,i+1,v,k);
    v.push_back(arr[i]);
    f(arr,n,i+1,v,k);
    
}
int main(){
  int arr[]={1,2,3,4,5};
  int n=5;
  vector<int>v;
  f(arr,n,0,v,3);
}
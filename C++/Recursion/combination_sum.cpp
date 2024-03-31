#include<bits/stdc++.h>
using namespace std;
// this code will give you all combination and its permutation also...
/*
2  2  2  2  
2  3  3  <-|
3  2  3    | combination but also permutation
3  3  2  <-|
3  5  
5  3 
 */
void fpermutationwala(int arr[], int n,vector<int>v,int target){
    if(target==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<"  ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return ;
    for(int i=0;i<n;i++){
        v.push_back(arr[i]);
        fpermutationwala(arr,n,v,target-arr[i]);
        v.pop_back();
    }

}

void f(int arr[], int n,vector<int>v,int target,int idx){
    if(target==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<"  ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return ;
    for(int i=idx;i<n;i++){
        v.push_back(arr[i]);
        f(arr,n,v,target-arr[i],i);
        v.pop_back();
    }

}

int main(){
    int arr[]={2,3,5};
    int n=3;
    vector<int>v;
    int target=8;
    // fpermutationwala(arr,n,v,target);
    f(arr,n,v,target,0);
}
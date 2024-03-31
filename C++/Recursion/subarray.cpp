#include<bits/stdc++.h>
using namespace std;
void f(int *arr,int n,int i,vector<int>v){
    if(i==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<"  ";
        }cout<<endl;
        return;
    }

    f(arr,n,i+1,v);
    if(v.size()==0 || arr[i-1]==v.back()){
        v.push_back(arr[i]);
        f(arr,n,i+1,v);
    }
    

}
int main(){
    int arr[]={1,2,3,4};
    int n=4;
    vector<int>v;
    f(arr,n,0,v);
}
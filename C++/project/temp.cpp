#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n+1);
    for(int i=0; i<1+n; i++){
        cin>>v[i];
    }
    int i=0;
    while(i<n){
        if(i==v[i]-1){
            i++;
        }
        else{
            swap(v[i],v[v[i]-1]);
        }
    }
    for(int i=0; i<1+n; i++){
        cout<<v[i]<<" ";
    }
}
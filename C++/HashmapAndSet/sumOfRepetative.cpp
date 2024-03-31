#include<bits/stdc++.h>
using namespace std;
int main(){

    int arr[] = {1,2,3,1,3,4,5,6,3,5,6};
    // 1+6+3
    int n = sizeof(arr)/sizeof(arr[0]);

    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    int sum=0;

    for(auto it : mp){
        if(it.second > 1){
            sum+= it.first;
        }
    }

    cout<<"sum of repetative element : "<<sum;

}
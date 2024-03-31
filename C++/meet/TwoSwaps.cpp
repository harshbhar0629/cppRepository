#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int actualIndexOfEle(vector<int>a,int k){
    for(int i=0;i<a.size();i++){
        if(k==a[i]) return i;
    }
    return 0;
}

bool isPossibleToconvertIntoSortedArrayByTwoSwaps(vector<int>& v,int n){
    auto a =v;
    int c=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]!=v[i]){
            if(c<2){
                swap(v[i],v[actualIndexOfEle(v,a[i])]);
                c++;
            }
            else{
                c=-1;
                break;
            }
        }
    }
    cout<<c<<endl;
    if(c==-1 || c==1) return false;
    else return true;
    // return c>0? 1: 0;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(isPossibleToconvertIntoSortedArrayByTwoSwaps(arr,n)){
        cout<<"Yes it is possible"<<endl;
    }
    else {
        cout<<"Not Possible"<<endl;
    }



}
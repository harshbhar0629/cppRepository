#include<bits/stdc++.h>
using namespace std;

int maxLengthZeroSubarraySum(vector<int> &v){
    
    int  n= v.size();
    unordered_map<int,int> mp;
    int prefixSum=0;
    int maxLen = -1;

    for(int i=0;i<n;i++){
        prefixSum += v[i];
        if(mp.find(prefixSum) != mp.end()){
            maxLen = max(maxLen , i - mp[prefixSum]);
        }
        else mp[prefixSum] = i;
    }
    
    return maxLen;
}

int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<< maxLengthZeroSubarraySum(v)<<endl;

}
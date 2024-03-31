#include <bits/stdc++.h>
using namespace std;


int distinct_subarray(vector<int>&nums){
    
    int n = nums.size();
    int ans =0;
    for(int i=0; i<n; i++){
        set<int>s;
        for(int j=i; j<n; j++){
            cout<<nums[j]<<"  ";
            s.insert(nums[j]);
            int sz = s.size();
            ans+=(sz*sz);
        }cout<<endl;
    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<distinct_subarray(v);

    return 0;
}
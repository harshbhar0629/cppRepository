// https://leetcode.com/contest/biweekly-contest-113/problems/minimum-right-shifts-to-sort-the-array/
#include <bits/stdc++.h>
using namespace std;

int minimumRightShifts(vector<int>&v){
    int n = v.size();
    for(int i=0; i<n; i++){
        v.push_back(v[i]);
    }
    int idx=-1;
    for(int i=0;i<v.size()-n+1; i++){
        bool check = true;
        for(int j=i; j<i+n-1; j++){
            if(v[j]>v[j+1]){
                check = false;
                break;
            }
        }
        if(check){
            idx=i;
            break;
        }
    }
    if(idx==-1) return -1;
    return (n-idx)%n;
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<minimumRightShifts(v);

    return 0;
}
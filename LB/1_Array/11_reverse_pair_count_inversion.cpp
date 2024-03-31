// https://leetcode.com/problems/reverse-pairs/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {

    int ans=0;

    void mergeAll(vector<int>&v,int lo, int mid, int hi){
        vector<int>b;
        int i = lo , j = mid+1;
        while(i<=mid and j<=hi){
            if((ll)v[i] > (ll)2*v[j]){
                ans += mid - i +1;
                j++;
            }
            else i++;
        }
        i = lo, j= mid+1;
        while(i<=mid and j<=hi){
            if(v[i] < v[j]){
                b.push_back(v[i++]);
            }
            else {
                b.push_back(v[j++]);
            }
        }
        while(i<=mid){
            b.push_back(v[i++]);
        }
        while(j<=hi){
            b.push_back(v[j++]);
        }
        for(int k=lo; k<=hi; k++){
            v[k] = b[k-lo];
        }
    }

    void merge(vector<int>& v, int lo, int hi){
        if(lo==hi) return;
        int mid = (lo+hi)/2;
        merge(v, lo, mid);
        merge(v, mid+1, hi);
        mergeAll(v, lo , mid, hi);
    }

public:
    int reversePairs(vector<int>& nums) {
        merge(nums, 0 , nums.size()-1);
        return ans;
    }
};

int main(){
    

    return 0;
}
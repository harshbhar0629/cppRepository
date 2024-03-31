// https://leetcode.com/contest/weekly-contest-376/problems/minimum-cost-to-make-array-equalindromic/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool f(ll& m){
    string s = to_string(m);
    for(int i=0; i<s.size()/2; i++){
        if(s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}

ll minimumCost(vector<int>& nums){
    int n = nums.size();
    auto m = nums.begin() + n/2;
    nth_element(nums.begin(), m, nums.end());

    ll lo = nums[n/2];
    ll hi = nums[n/2];
    ll minCost = 1e17;

    while(lo>0 and !f(lo)) lo--;
    while(hi<1e17 and !f(hi)) hi++;

    for(auto& x: {lo,hi}){
        ll cost = 0;
        for(auto& y: nums){
            cost += abs(y-x);
        }
        minCost = min(cost, minCost);
    }

    return minCost;
}

int main(){
    

    return 0;
}
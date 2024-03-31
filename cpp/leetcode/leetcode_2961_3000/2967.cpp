#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/description/

#define ll long long int

bool f(ll &n){
    // cout << n << " ";
    string s = to_string(n);
    for (int i = 0, j = s.size() - 1; i < j; i++,j--){
        if(s[i]!=s[j])
            return false;
    }
    return true;
}

ll minimumCost(vector<int> &nums){
    int n = nums.size();
    // sort(nums.begin(), nums.end());
    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

    int val = nums[n / 2];
    ll i = val;
    ll j = val;
    cout << endl << endl;
    
    while(!f(i))
        i--;
    cout << endl << endl;
    
    while(!f(j))
        j++;

    int minCost = INT_MAX;
    for(auto x: {i,j}){
        int cost = 0;
        for (int i = 0; i < n; i++){
            cost += abs(nums[i] - x);
        }
        minCost = min(minCost, cost);
    }
    cout << endl << endl;
    return minCost;
}

int main(){
    
    vector<int> v;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string t;
    while (getline(ss, t, ',')){
        ll val = stoi(t);
        v.push_back(val);
    }


    cout << minimumCost(v);

    return 0;
}

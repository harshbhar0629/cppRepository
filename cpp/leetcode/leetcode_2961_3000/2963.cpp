#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-the-number-of-good-partitions/description/

#define ll long long int

int N = 1e9 + 7;

ll f(int x, int y){
    if(y==0)
        return 1;
    ll ans = f(x, y / 2)%N;

    return y % 2 ? (ans * ans)%N * x : (ans * ans)%N;
}

int numberOfGoodPartitions(vector<int> &nums){
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i<n; i++){
        mp[nums[i]] = i;
    }

    int cnt = 0;
    int i{0}, j{0};

    while(i<n){
        j = max(j, mp[nums[i]]);
        if(i==j){
            //  1 2 3 4 3 6
            //i=0, j=0 means this is a good partition every time we require 
            // a last index or last occurence of considering a subaArray  
            cnt++;
        }
        i++;
    }

    return f(2, cnt - 1);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for (int i = 0; i<n; i++){
        cin >> v[i];
    }

    cout << numberOfGoodPartitions(v);

    return 0;
}
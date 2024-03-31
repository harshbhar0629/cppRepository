#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

#define ll long long int

ll countSubarrays(vector<int>& nums, int k){
    int n = nums.size();
    int maxi = nums[0];

    for (int i = 1; i < n; i++){
        maxi = max(nums[i], maxi);
    }

    int i{0}, j{0};
    ll cnt{0}, count{0};
    while(i<n){
        if(nums[i] == maxi)
            cnt++;
        while (j < n and cnt>=k){
            count += n - i;
            if(nums[j] == maxi)
                cnt--;
            j++;
        }
        i++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    cout << countSubarrays(v,k);
}
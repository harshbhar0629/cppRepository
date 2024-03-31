#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/contiguous-array/description/
//  https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

class Solution
{
public:
    int maxLen(vector<int>& arr, int n)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        int len = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += (arr[i] == 1) ? 1 : -1;
            if (mp.find(sum) != mp.end())
            {
                len = max(len, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return len;
    }
};

int main(){
    // int n;
    // cin >> n;
    // int v[n];
    vector<int> v;
    for (int i = 0; i < 1000; i++){
        int x;
        cin >> x;
        if(x==-1){
            break;
        }
        v.push_back(x);
    }
    Solution s;
    cout << v.size() << "\n";
    cout << s.maxLen(v, v.size());

    return 0;
}
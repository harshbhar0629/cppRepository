#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/equal-0-1-and-23208/1?

#define ll long long int
class Solution
{
public:
    ll getSubstringWithEqual012(string s)
    {
        int n = s.size();
        map<pair<int, int>, int> mp;
        int one = 0, two = 0, zero = 0;
        ll cnt = 0;
        mp[{0, 0}] = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one++;
            if (s[i] == '2')
                two++;
            if (mp.find({zero - one, one - two}) != mp.end())
            {
                cnt += mp[{zero - one, one - two}];
            }
            mp[{zero - one, one - two}]++;
        }
        return cnt;
    }
};

int main(){
    string s;
    cin >> s;
    Solution s;
    cout << s.getSubstringWithEqual012(s);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-duplicate-substring/description/

#define ll unsigned long long
const ll mod = 1e13 + 7;
class Solution
{
    string ans = "";
    bool f(string &s, vector<ll> &pow, int mid)
    {

        ll hash1 = 0;
        for (int i = 0; i < mid; i++)
        {
            hash1 = (hash1 * 31 + (s[i] - 'a' + 1)) % mod;
        }

        unordered_set<ll> st;
        int start = 0;
        st.insert(hash1);

        for (int i = mid; i < s.size(); i++)
        {
            // cout<<hash1<<" ";
            hash1 = (hash1 - (pow[mid - 1] * (s[start] - 'a' + 1) % mod) + mod) % mod;
            hash1 = (hash1 * 31 + (s[i] - 'a' + 1)) % mod;
            start++;
            if (st.find(hash1) != st.end())
            {
                // cout<<hash1<<" ";
                string t = s.substr(start, mid);
                if (t.size() > ans.size())
                {
                    ans = t;
                }
                return true;
            }
            st.insert(hash1);
        }
        // cout<<endl;
        return false;
    }

public:
    string longestDupSubstring(string s)
    {

        int n = s.size();
        if (n <= 2)
        {
            return (n > 1) ? ((s[0] == s[1]) ? s.substr(1) : "") : "";
        }

        vector<ll> pow(n, 1);
        for (int i = 1; i < n; i++)
        {
            pow[i] = (pow[i - 1] * 31) % mod;
        }

        int lo = 1, hi = n;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            bool flag = f(s, pow, mid);

            if (flag)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
int main(){
    

    return 0;
}
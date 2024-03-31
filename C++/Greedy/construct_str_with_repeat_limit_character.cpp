#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/construct-string-with-repeat-limit/description/

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        priority_queue<pair<char, int>> pq;
        vector<int> v(26, 0);
        for (auto ch : s)
        {
            v[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
                pq.push({i + 'a', v[i]});
        }

        string ans = "";
        while (pq.size() > 0)
        {
            auto curr = pq.top();
            pq.pop();
            char ch = curr.first;
            int freq = min(repeatLimit, curr.second);

            for (int i = 0; i < freq; i++)
            {
                ans += ch;
            }

            if (curr.second - freq > 0)
            {
                if (!pq.empty())
                {
                    auto next = pq.top();
                    pq.pop();
                    ans += next.first;
                    next.second--;
                    if (next.second > 0)
                    {
                        pq.push({next.first, next.second});
                    }
                    pq.push({curr.first, curr.second - freq});
                }
                else
                    return ans;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
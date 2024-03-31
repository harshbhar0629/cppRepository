#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-performance-of-a-team/description/

#define ll long long int
#define pi pair<int, int>
class Solution
{

    const int mod = 1e9 + 7;
    static bool cmp(const pi &p1, const pi &p2)
    {
        return p1.second > p2.second;
    }

public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {

        vector<pi> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({speed[i], efficiency[i]});
        }

        sort(v.begin(), v.end(), cmp);
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        ll sum = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (pq.size() == k)
            {
                sum -= pq.top().first;
                pq.pop();
            }
            sum += v[i].first;
            pq.push({v[i].first, v[i].second});
            ans = max(ans, sum * v[i].second);
        }
        return ans % mod;
    }
};

int main(){
    

    return 0;
}
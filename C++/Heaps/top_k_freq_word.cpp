#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/top-k-frequent-words/

class cmp
{
public:
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2)
    {
        if (p1.first == p2.first)
        {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
};
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (auto word : words)
        {
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto it : mp)
        {
            //
            pq.push({it.second, it.first});
            if (k < pq.size())
            {
                // cout<<pq.top().first<<" "<<pq.top().second<<endl;
                pq.pop();
            }
        }

        vector<string> ans(k);
        while (k--)
        {
            auto it = pq.top();
            pq.pop();
            ans[k] = it.second;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
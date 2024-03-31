#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/contest/weekly-contest-388/problems/shortest-uncommon-substring-in-an-array/

class Solution
{
    unordered_map<string, int> mp;
    unordered_set<string> st[105];

public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            // fetching current string
            string s = arr[i];
            for (int j = 0; j < s.size(); j++)
            {
                // generate all possible unique substring and insert into <set>->DS
                string now = "";
                for (int k = j; k < s.size(); k++)
                {
                    now += s[k];
                    // store all substring in ith index so that each index will tell how many unique substring exist for current idx
                    st[i].insert(now);
                }
            }

            // store all unique substring in map so it having the data of over-all substring
            for (auto it : st[i])
            {
                mp[it]++;
            }
        }

        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            // for every index set[i] will give unique substring of ith string
            string res = "";
            for (auto it : st[i])
            {
                // checking this substring is exist in any other substring or not
                if (mp[it] == 1)
                {
                    // means it will not exist in any other substring
                    if (res == "")
                    {
                        res = it;
                    }
                    // if current substring is lesser in size then update resulting string o/w if both equal in size then store lexicographically smallest substring
                    else if (it.size() < res.size() || (it.size() == res.size() and it < res))
                    {
                        res = it;
                    }
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
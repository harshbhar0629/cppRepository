#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/v

#define ll long long int
// class Trie{
//  public:
//     map<pair<char,char>,Trie*>child;
//     int cnt;
//     Trie(){
//         cnt=0;
//     }
//     ~Trie(){}
// };

class Solution
{
    // Trie* root=new Trie();
    // ll ans=0;

    // void PS(const string& word){
    //     Trie* curr = root;
    //     for(int i=0; i<word.size(); i++){
    //        if(curr->child.find({word[i],word[word.size()-i-1]}) == curr->child.end()){
    //             curr->child[{word[i],word[word.size()-1-i]}] = new Trie();
    //         }
    //         curr = curr->child[{word[i],word[word.size()-i-1]}];
    //         ans+=curr->cnt;
    //     }
    //     curr->cnt++;
    // }

    // ll solve(vector<string>& w){
    //     int n = w.size();
    //     ans=0;
    //     for(int i=0; i<n; i++){
    //         PS(w[i]);
    //     }

    //     return ans;
    // }

    vector<int> Z(string &s)
    {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n; i++)
        {
            if (i <= r)
            {
                z[i] = min(z[i - l], r - i);
            }
            while (i + z[i] < n and s[z[i]] == s[z[i] + i])
            {
                z[i]++;
            }
            if (i + z[i] - 1 > r)
            {
                r = i + z[i] - 1;
                l = i;
            }
        }

        return z;
    }

public:
    ll countPrefixSuffixPairs(vector<string> &words)
    {
        ios_base::sync_with_stdio(NULL);
        cin.tie(0);
        // return solve(words);
        unordered_set<int> cnt;
        unordered_map<string, ll> mp;
        ll ans = 0;

        for (auto word : words)
        {
            vector<int> z = Z(word);
            int n = word.size();
            for (int i = 1; i < n; i++)
            {
                if (n - i == z[i] and cnt.find(n - i) != cnt.end())
                {
                    string t = word.substr(0, z[i]);
                    ans += mp[t];
                }
            }
            if (mp.find(word) != mp.end())
            {
                ans += mp[word];
            }
            mp[word]++;
            cnt.insert(n);
        }

        return ans;
    }
};
int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-happy-prefix/

#define ll long long int
const ll mod = 1e9+7;
class Solution {

    int kmp(string& s){
        int n = s.size();
        vector<int>lps(n,0);
        int i=1, len=0;

        while(i<n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len > 0){
                    len = lps[len - 1];
                }
                else{
                    i++;
                }
            }
        }
        return lps[n-1];
    }

public:
    // TC: O(N), SC: O(N)
    string longestPrefix(string s) {
        int len = kmp(s);
        return s.substr(0,len);
    }

    // SC:O(1), TC:(N)
    string longestPrefix1(string s){

        int n = s.size();
        ll pow = 1;

        ll hash_pre = 0, hash_suff = 0;
        int idx = -1;

        for (int i = 0; i < n - 1; i++){

            // hash_pre multiply by 31 bcoz we have to inc power by one
            hash_pre = (hash_pre * 31 + (s[i] - 'a' + 1)) % mod;
            hash_suff = (hash_suff + (s[n - i - 1] - 'a' + 1) * pow) % mod;

            if (hash_pre == hash_suff){
                idx = i;
            }
            pow = (pow * 31) % mod;
        }

        if (idx == -1)
        {
            return "";
        }

        return s.substr(0, idx + 1);
    }
};

int main(){


    return 0;
}
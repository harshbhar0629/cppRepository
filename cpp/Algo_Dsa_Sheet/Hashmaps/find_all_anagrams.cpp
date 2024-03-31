#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution
{
public:
   // TC: O(26*s.size()) 
    vector<int> findAnagrams(string s, string p){

        int ps = p.size();
        vector<int> res, ch_s(26, 0), ch_p(26, 0);

        for (int i = 0; i < ps; i++){
            ch_p[p[i] - 'a']++;
        }

        int start = 0, end = 0;
        while (end < s.size()){
            ch_s[s[end] - 'a']++;
            int len = end - start + 1;

            if (len == ps and ch_s == ch_p){
                res.push_back(start);
            }

            if (len >= ps){
                ch_s[s[start] - 'a']--;
                start++;
            }
            end++;
        }

        return res;
    }
};

int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-window-substring/description/

class Solution{
    /**
     * first store all occurence of string t in a map DS
     * iterate in all char of string s and take count variable for store valid character cnt
     * valid character are those character which come in string t
     * if(count == t.size()) then move our start pointer and decrease all occurence of character
     * which is not a part of string t and suppose if we reach that point which having a part of our substring
     * then we can exit from loop and store windowLength and its starting index
    */
public:
    string minWindow(string s, string t){

        int n = s.size();
        int m = t.size();
        if (m > n){
            return "";
        }
        vector<int> map(130, 0);

        for (int i = 0; i < m; i++){
            map[t[i]]++;
        }

        int cnt = m;
        int start = 0, end = 0;
        int startIdx = -1, len = 1e8;

        while (end < n){
            if (--map[s[end]] >= 0){
                cnt--;
            }
            while (cnt == 0){
                if (end - start + 1 < len){
                    // cout<<"HELLLO\n";
                    startIdx = start;
                    len = end - start + 1;
                    // cout<<startIdx<<" "<<len<<"\n";
                }
                if (++map[s[start]] > 0) {
                    cnt++;
                }
                start++;
            }
            end++;
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, len);

        // int n = s.size();
        // int m = t.size();
        // if(m>n){
        //     return "";
        // }
        // unordered_map<char, int> tmp;

        // for (int i = 0; i<m; i++){
        //     tmp[t[i]]++;
        // }
        // unordered_map<char, int> smp;
        // int cnt = 0, start = 0;
        // int miniLen = 1e7, startIdx = -1;

        // for (int i = 0; i < n; i++){
        //     smp[s[i]]++;
        //     if (smp[s[i]] <= tmp[s[i]]){
        //         cnt++;
        //     }

        //     if(cnt == m){
        //         while(smp[s[start]] > tmp[s[start]] || tmp[s[start]] == 0){
        //             if(smp[s[start]] > tmp[s[start]]){
        //                 smp[s[start]]--;
        //             }
        //             start++;
        //         }
        //         int windowLength = (i - start + 1);
        //         if(miniLen > windowLength){
        //             startIdx = start;
        //             miniLen = windowLength;
        //         }
        //     }
        // }
        // if(startIdx == -1){
        //     return "";
        // }

        // return s.substr(startIdx, miniLen);
    }
};
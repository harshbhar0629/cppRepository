#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-palindrome/

class Solution
{

    // bool isPalin(string& s, int j){
    //     int i=0;
    //     while(i<j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //         i++,j--;
    //     }

    //     return true;
    // }

    // string solve(string s){
    // int n = s.size();
    // int idx = 0;
    // for(int j=n-1; j>0; j--){
    //     if(isPalin(s, j)){
    //         idx = j;
    //         break;
    //     }
    // }

    // string ans = s;

    // for(int i=idx+1; i<n; i++){
    //     ans = s[i] + ans;
    // }
    // return ans;
    // }

    int computeLps(const string pat){
        int n = pat.size();
        vector<int> lps(n, 0);
        int i = 1, len = 0;

        while (i < n)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len > 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        //debugging
        // for (int i = 0; i < lps.size(); i++){
        //     cout << lps[i] << " ";
        // }
        return lps[n - 1];
    }

public:
    string shortestPalindrome(string s)
    {

        string rev(s);
        reverse(rev.begin(), rev.end());
        string pattern = s + '#' + rev;

        int len = computeLps(pattern);
        string ans = rev.substr(0, rev.size() - len) + s;

        return ans;
    }
};

int main(){
    

    return 0;
}
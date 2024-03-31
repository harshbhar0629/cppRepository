#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
    // O(N^2)
    string solve(string s){
        if(s=="") return s;
        int n = s.size();
        int start = 0, maxLen = 1;

        for(int k=0; k<n; k++){
            // first handle even case
            int len = 0, i = k, j = k+1;
            while(i>=0 and j<n and s[i]==s[j]){
                len+=2;
                i--, j++;
            }
            if(len > maxLen){
                maxLen = len;
                start = i+1;
            }

            // for odd case
            len = 1, i = k-1, j = k+1;
            while(i>=0 and j<n and s[i]==s[j]){
                len+=2;
                i--, j++;
            }
            if(len > maxLen){
                maxLen = len;
                start = i+1;
            }
        }
        string ans("");
        for(int i=0; i<maxLen; i++){
            ans+=s[start+i];
        }
        return ans;
    }

public:
    string longestPalindrome(string s)
    {

        int n = s.size();
        string temp = "";

        temp += "@#";
        for (int i = 0; i < n; i++)
        {
            temp += s[i];
            temp += '#';
        }
        temp += '%';

        int m = temp.size();
        vector<int> lps(m, 0);
        // also similar to brute force
        // (trivial algorithm)
        // for (int i = 1; i < m - 1; i++)
        // {
        //     while (temp[i + lps[i] + 1] == temp[i - lps[i] - 1])
        //     {
        //         lps[i]++;
        //     }
        // }

        int c = 0, r = 0;

        // O(N)
        for (int i = 1; i < m - 1; i++)
        {
            // c is center and we want a left most character and form mirror image
            int m = c - (i - c);
            if (i < r)
            {
                lps[i] = min(lps[m], r - i);
            }
            while (temp[i + lps[i] + 1] == temp[i - lps[i] - 1])
            {
                lps[i]++;
            }
            // suppose our circle is known then update center and right most character
            if (i + lps[i] > r)
            {
                r = lps[i] + i;
                c = i;
            }
        }

        int idx = 0;
        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            if (lps[i] > maxi)
            {
                idx = i;
                maxi = lps[i];
            }
            // cout<<lps[i]<<" ";
        }
        // cout<<endl;
        // cout<<maxi<<" "<<idx;

        string ans = "";
        if (idx % 2 == 0)
        {
            int i = 2;
            maxi--;
            ans = temp[idx];
            while (maxi > 0)
            {
                maxi -= 2;
                ans = temp[idx - i] + ans;
                ans += temp[idx + i];
                i += 2;
            }
        }
        else
        {
            int i = 1;
            while (maxi > 0)
            {
                maxi -= 2;
                ans = temp[idx - i] + ans;
                ans += temp[idx + i];
                i += 2;
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}
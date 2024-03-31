#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/search-pattern0205/1

class Solution{
public:
    // Brute force O(mn)
    static bool isPatExist(string s, string pat){
        int n = s.size();
        int m = pat.size();

        for (int i = 0; i <= n-m; i++){

            if(s[i] == pat[0]){
                for (int j = 0; j < m; j++){
                    if (s[i+j] != pat[j]){
                        break;
                    }
                    if(j == m-1){
                        cout << j << " ";
                        return true;
                    }
                }
            }
        }

        return false;
    }

    // halka sa opt
    bool isPatExist1(string s, string pat)
    {
        int n = s.size();
        int m = pat.size();

        for (int i = 0; i <= n - m; i++)
        {

            if (s[i] == pat[0])
            {
                bool flag = false;
                for (int j = 0; j < m; j++)
                {
                    if (s[i] != pat[j]){
                        break;
                    }
                    else{
                        i++;
                        flag = true;
                    }
                }
                if(flag){
                    i--;
                }
            }
        }

        return false;
    }

    // full optimised(m+n)
    vector<int> knuthMorris(string pat, string txt)
    {

        int m = pat.size();
        int n = txt.size();
        vector<int> lps(m, 0);
        int i = 1, len = 0;

        // lps code..
        while (i < m)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len > 0){
                    // if not equal then goto prev index value which says (len-1)th index p end hone wala sbse bda common prefix
                    len = lps[len - 1];
                }
                else
                {
                    len = 0;
                    lps[i] = 0;
                    i++;
                }
            }
        }

        vector<int> ans;
        int j = 0;
        i = 0;

        // for(int i=0; i<m; i++){
        //     cout<<lps[i]<< " ";
        // }

        // check pattern string in string s -> using lps
        while (i < n)
        {
            if (pat[j] == txt[i])
            {
                i++, j++;
            }
            if (j == m)
            {
                ans.push_back(i - j + 1);
                j = lps[j - 1];
            }
            else if (pat[j] != txt[i])
            {
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    // if  not equal then find ki (j-1)th index p end hone wala sbse bda common prefix and suffix and goto that index
                    j = lps[j - 1];
                }
            }
        }
       
        if (ans.size() == 0)
        {
            return {-1};
        }

        return ans;
    }
};

// s-> aylnlfdxfi
// dxfi

int main()
{

    Solution s1;
    string s, pat;
    cin >> s >> pat;

    // cout << s1.isPatExist(s, pat) << endl;
    vector<int> ans = s1.knuthMorris(s, pat);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
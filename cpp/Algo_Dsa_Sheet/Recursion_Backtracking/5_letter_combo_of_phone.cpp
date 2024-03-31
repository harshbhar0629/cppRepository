#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void f(int i, string &s, string &digits)
    {
        if (i == digits.size())
        {
            ans.push_back(s);
            return;
        }

        for (auto ch : keys[digits[i] - '0'])
        {
            s += ch;
            f(i + 1, s, digits);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return ans;
        }
        string s = "";
        f(0, s, digits);

        return ans;
    }
};

int main(){
    

    return 0;
}
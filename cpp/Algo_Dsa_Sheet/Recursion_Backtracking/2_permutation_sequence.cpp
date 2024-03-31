#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/permutation-sequence/

class Solution
{
    string ans = "";
    void f(int n, int k, string &s)
    {
        if (n == 0)
        {
            return;
        }
        int fact = 1;
        for (int i = 2; i < n; i++)
        {
            fact *= i;
        }
        int idx = k / fact;
        if (k % fact == 0)
        {
            idx--;
        }

        ans += s[idx];

        string ros = s.substr(0, idx) + s.substr(idx + 1);
        f(n - 1, k - idx * fact, ros);
    }

public:
    string getPermutation(int n, int k)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
        {
            s += to_string(i);
        }

        f(n, k, s);
        return ans;
    }
};

int main(){
    

    return 0;
}
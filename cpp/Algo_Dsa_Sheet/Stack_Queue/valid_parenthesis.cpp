#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/valid-parentheses/description/

class Solution
{
public:
    bool isValid(string s)
    {

        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (st.size() == 0 || s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
                continue;
            }
            if (!st.empty() and st.top() == '(' and s[i] == ')')
            {
                st.pop();
            }
            else if (!st.empty() and st.top() == '[' and s[i] == ']')
            {
                st.pop();
            }
            else if (!st.empty() and st.top() == '{' and s[i] == '}')
            {
                st.pop();
            }
            else
                return false;
        }
        return st.size() == 0;
    }
};

int main(){
    

    return 0;
}
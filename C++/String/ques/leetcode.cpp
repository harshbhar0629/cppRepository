#include <bits\stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int i = haystack.find(needle);
    if (i != string::npos)
    {
        return i;
    }
    else
        return i;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << strStr(s, t);
}
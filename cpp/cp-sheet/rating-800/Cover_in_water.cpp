#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1900/A

int main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        auto solve = [&]()
        {
            int cntEmpty = 0, maxEmpty = 0;
            int empty = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '.')
                {
                    empty++;
                }
                else
                {
                    maxEmpty = max(maxEmpty, empty);
                    cntEmpty += empty;
                    empty = 0;
                }
                // cout << maxEmpty << " " << empty << " " << cntEmpty << "\n";
            }
            maxEmpty = max(maxEmpty, empty);
            cntEmpty += empty;

            if (maxEmpty > 2)
            {
                cout << "2\n";
            }
            else
            {
                cout << cntEmpty << "\n";
            }
        };
        solve();
    }
}
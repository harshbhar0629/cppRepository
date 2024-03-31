#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << endl;

    cout << endl;

    int t;
    cin >> t;

    vector<int> pre(n + 2, 0);
    while (t--)
    {
        int i, j, val = 1;
        cin >> i >> j;

        pre[i] += val;
        pre[j + 1] -= val;
    }
    cout << endl;
    for (int i = 1; i <= n + 1; i++)
    {
        pre[i] += pre[i - 1];
    }
    cout << endl
         << endl;

    cin >> t;
    while (t--)
    {

        int x;
        cin >> x;
        cout << v[x] + pre[x] << endl;
    }
}
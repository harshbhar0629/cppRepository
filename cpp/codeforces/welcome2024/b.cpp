#include <bits/stdc++.h>
using namespace std;

void s()
{
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-')
                cnt--;
            else
                cnt++;
        }
    cout << abs(cnt) << endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        s();
    }

    return 0;
}

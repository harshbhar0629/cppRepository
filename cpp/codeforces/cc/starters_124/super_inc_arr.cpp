#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        t--;
        int n, k, x;
        // given A[k] = x; very next element must greater than the sum of all previous element
        cin >> n >> k >> x;

        if (k > 30)
        {
            cout << "No\n";
            continue;
        }

        int minVal = (1 << (k - 1));
        if (x >= minVal)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    bitset<10> mask;
    mask[0] = 1;
    vector<int> a = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        cout << (mask << a[i]) << " ";
        mask |= (mask << a[i]);
        cout << mask.to_ulong() << " ";
        cout << mask << " \n";
    }

    return 0;
}
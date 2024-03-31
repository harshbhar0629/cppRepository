#include <bits/stdc++.h>
using namespace std;

class bank
{
public:
    int data;
    bank(int d)
    {
        data = d;
    }
};

int main()
{
    int x;
    cin >> x;
    bank b(x);
    cout << "data is: " << (b.data);

    return 0;
}
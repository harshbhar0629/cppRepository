#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/START124D/problems/BINPARITY

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        while (n > 0)
        {
            int bit = n % 2;
            cnt += bit;
            n /= 2;
        }

        if (cnt % 2 == 0)
        {
            cout << "Even\n";
        }
        else
        {
            cout << "Odd\n";
        }
    }

    return 0;
}
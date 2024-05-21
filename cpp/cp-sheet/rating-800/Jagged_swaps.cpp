#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1896/A

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        auto solve = [&]()
        {
            for (int j = 0; j < 10; j++){
                for (int i = 1; i < n - 1; i++)
                {
                    if (a[i - 1] < a[i] and a[i] > a[i + 1])
                    {
                        swap(a[i], a[i + 1]);
                    }
                }
            }

                for (int i = 1; i < n; i++)
                {
                    if (a[i - 1] > a[i])
                    {
                        return "NO";
                    }
                }
            return "YES";
        };
        cout << solve() << "\n";
    }

    return 0;
}
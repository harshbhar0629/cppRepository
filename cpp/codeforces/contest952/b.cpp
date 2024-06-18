#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 3)
            cout << n;
        else
            cout << 2;
        cout << endl;
        // pair<int, int> ans;
        // for (int i = 2; i <= n; i++){
        //     int sum = 0;
        //     int mult = 1;
        //     while(mult*i <= n){
        //         sum += mult*i;
        //         mult++;
        //     }

        //     if(ans.second <= sum){
        //         ans.first = i;
        //         ans.second = sum;
        //     }
        // }

        // cout << ans.first << "\n";
    }

    return 0;
}
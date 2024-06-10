#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t>0){
        t--;
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int cnt = 1e9;
        for (int i = 1; i < n; i++)
        {
            cnt = min(cnt, max(a[i], a[i - 1]) - 1);
        }

        cout << cnt << "\n";
    }
    return 0;
}
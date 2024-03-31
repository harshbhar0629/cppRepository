#include <bits/stdc++.h>
using namespace std;

void s()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int maxi = 0;
    for (int i = 0; i<n; i++){
        maxi = max(maxi, v[i]);
    }
    if(2*maxi <= n){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
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

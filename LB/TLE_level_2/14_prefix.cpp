#include <bits/stdc++.h>
using namespace std;

// 1D

//********** prefix sum*********
// vector<int>pre(n,0);
// o(n^2)
// for(int i=0; i<n; i++){
//     for(int j=0; j<=i; j++){
//         pre[i] += v[j];
//     }
// }

// O(n)
// pre[0] = v[0];
// for(int i=1; i<n; i++){
//     pre[i] += pre[i-1] + v[i];
// }

// printing
// for(int i=0; i<n; i++){
//     cout<<pre[i]<<" ";
// }

// ******************suffix sum***********************

// vector<int>suf(n,0);
// O(n^2)
// for(int i=n-1; i>=0; i--){
//     for(int j=n-1; j>=i; j--){
//         suf[i] += v[j];
//     }
// }

// O(N)
// suf[n-1] = v[n-1];
// for(int i=n-2; i>=0; i--){
//     suf[i] += suf[i+1] + v[i];
// }

// printing
// for(int i=0; i<n; i++){
//     cout<<suf[i]<<" ";
// }

int main()
{
    int n;
    cin >> n;
    int n, m;
    cin >> n >> m;
    int g[n + 1][m + 1], p[n + 1][m + 1]{};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            p[i][j] = g[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    cout << "\n\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << p[c][d] << " " << p[c][b - 1] << " " << p[a - 1][d] << " " << p[a - 1][b - 1] << endl;
        ;
        int ans = p[c][d] - p[c][b - 1] - p[a - 1][d] + p[a - 1][b - 1];

        cout << ans << "\n";
    }

    cout << endl;
}
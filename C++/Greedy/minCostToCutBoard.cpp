// https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares
// https://www.spoj.com/problems/CHOCOLA/
#include <bits/stdc++.h>
using namespace std;

int minimumCostOfBreaking(vector<int> X, vector<int> Y)
{

    int ans = 0;
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());

    int v = 0, h = 0, vr = 1, hz = 1;

    while (v < X.size() and h < Y.size())
    {

        if (X[v] > Y[h])
        {
            ans += X[v] * vr;
            v++;
            hz++;
        }
        else
        {
            ans += Y[h] * hz;
            vr++;
            h++;
        }
    }
    while (v < X.size())
    {
        ans += X[v] * vr;
        v++;
        hz++;
    }
    while (h < Y.size())
    {
        ans += Y[h] * hz;
        vr++;
        h++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> v(n-1);
        vector<int> h(m-1);
        for (int i = 0; i < n-1; i++){
            cin >> v[i];
        }
        for (int j = 0; j < m-1; j++){
            cin >> h[j];
        }

        cout << minimumCostOfBreaking(v, h) << endl;
    }

    return 0;
}
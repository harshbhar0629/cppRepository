#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/CENS20A

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<string> v;
    for (int i = 0; i < n; i++){
        string t;
        cin >> t;
        v.push_back(t);
    }

    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
    int q;
    cin >> q;
    while(q--){
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        pre[r1][c1]++;
        pre[r2 + 1][c2 + 1]++;
        pre[r1][c2 + 1]--;
        pre[r2+1][c1]--;
    }

    for (int i = 0; i < m; i++){
        for (int j = 1; j < n; j++){
            pre[j][i] += pre[j - 1][i];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j < m; j++){
            pre[i][j] += pre[i][j-1];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if(pre[i][j] % 2 == 0){
                cout << v[i][j];
            }
            else{
                cout << ((v[i][j] == '1') ? '0' : '1');
            }
        }
        cout << "\n";
    }

    return 0;
}
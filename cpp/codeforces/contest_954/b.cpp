#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1986/problem/B

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int left, right, down, up;
                left = right = down = up = -1;
                if(j>0){
                    left = v[i][j - 1];
                }
                if(j+1<m){
                    right = v[i][j+1];
                }
                if(i>0){
                    up = v[i-1][j];
                }
                if(i+1<n){
                    down = v[i + 1][j];
                }
                if(v[i][j]>left and v[i][j]>right and v[i][j] > up and v[i][j]>down){
                    v[i][j] = max({left, right, up, down});
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
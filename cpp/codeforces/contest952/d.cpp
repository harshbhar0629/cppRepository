#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        int col = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (a[i][j] == '#')
                {
                    col = j;
                    break;
                }
            }
        }
        int row = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(a[j][i] == '#'){
                    row = j;
                    break;
                }
            }
        }
        cout << row + 1 << " " << col + 1 << "\n";
    }

    return 0;
}
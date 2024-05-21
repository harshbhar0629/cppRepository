#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1873/C

int main(){
    int t;
    cin >> t;
    while(t--){
        const int n = 10;
        vector<string> a(10);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        auto solve = [&]()
        {
            int score = 0;
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if(a[i][j] == 'X'){
                        int x = i, y = j;
                        if (x <= 4){
                            x++;
                        }
                        else{
                            x = n - x;
                        }
                        if (y <= 4){
                            y++;
                        }
                        else{
                            y = n - y;
                        }
                        score += min(x, y);
                    }
                }
            }

            return score;
        };

        cout << solve() << "\n";
    }

    return 0;
}
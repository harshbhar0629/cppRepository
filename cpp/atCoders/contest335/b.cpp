#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> res;
    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int k = 0; k <= n; k++){
                if(i+j+k <= n){
                    res.push_back({i, j, k});
                }
            }
        }
    }

    int s = res.size();
    sort(res.begin(), res.end());

    for (int i = 0; i < s; i++){
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }

    return 0;
}
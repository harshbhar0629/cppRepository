#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1881/A

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;

        auto solve = [&]()
        {
            int cnt = 0;
            while (s.size() < t.size()){
                s += s;
                cnt++;
            }
            s += s;
            int idx = -1;
            for (int i = 0; i <= s.size() - t.size(); i++){
                if(s.substr(i, t.size()) == t){
                    idx = i+t.size()-1;
                    break;
                }
            }

            return (idx == -1)? -1: (idx < s.size()/2)? cnt: 1+cnt;
        };

        cout << solve() << "\n";
    }
    

    return 0;
}
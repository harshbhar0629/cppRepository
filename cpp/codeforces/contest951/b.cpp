#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int x, y;
        cin >> x >> y;
        vector<int> v1, v2;

        do{
            v1.push_back(x % 2);
            x /= 2;
        } while (x);
        
        do{
            v2.push_back(y % 2);
            y /= 2;
        } while (y);

        while (v1.size() < v2.size()){
            v1.push_back(0);
        }
        while (v1.size() > v2.size()){
            v2.push_back(0);
        }
        // for (int i = 0; i < v1.size(); i++){
        //     cout << v1[i] << " " << v2[i] << "\n";
        // }

        long long int res = 1;
        for (int i = 0; i < v1.size(); i++){
            if(v1[i] == v2[i]){
                res *= 2;
            }
            else{
                break;
            }
        }

        cout << res << "\n";
    }

    return 0;
}
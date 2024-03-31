#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    string res = "";
    bool flag = false;

    for(auto ch: s){
        if(ch == '|'){
            flag = !flag;
            continue;
        }
        if(!flag){
            res += ch;
        }
    }

    cout << res << "\n";

    return 0;
}
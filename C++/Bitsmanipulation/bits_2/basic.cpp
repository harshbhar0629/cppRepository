#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int binary_decimal(string& s){
    int n = s.size();
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--){
        char ch = s[i];
        int num = ch - '0';
        ans += (num << (n - i - 1));
    }
    return ans;
}

int main(){
    string s = "00101011";
    cout << binary_decimal(s) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// /https://www.spoj.com/submit/FINDSR/

int computeLps(string s){
    int n = s.size();
    vector<int>lps(n,0);
    int i = 1, len = 0;

    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len > 0){
                len = lps[len - 1];
            }
            else{
                i++ ;
            }
        }
    }
    // a b c a b c a b c a b c
    // 0 0 0 1 2 3 4 5 6 7 8 9
    // for(int i=0; i<n; i++){
    //     cout << lps[i] << " ";
    // }
    // cout << endl;
    return lps[n - 1];
}

int nthRoot(const string s){
    int n = s.size();

    int val = computeLps(s);
    int deno = n - val;
    if (deno < n && n % deno == 0){
        return n / deno;
    }

    return 1;
}

int main(){

    string s;
    cin >> s;
    while(s != "*"){
        cout << nthRoot(s) << endl;
        cin >> s;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/tutorial/

vector<int> z_func(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++){
        if(i<=r){
            // i-l islia taki inka gap btayega ki starting s konse value ka ans lena h
            z[i] = min(z[i - l], r - i + 1);
            // cout << z[i] << " ";
        }
        // z[i] tels ki starting konse idx s compare kre or (z[i]+i) ki current konsa character match kre
        while(i+z[i] < n and s[z[i]] == s[z[i]+i]){
            z[i]++;
        }
    
        if(i+z[i] >= r){
            // cout << i << " ";
            l = i;
            r = i + z[i]-1;
        }
    }
    // cout << endl;
    return z;
}

vector<int> Z(string s, string pat){
    string temp = pat + "#" + s;
    vector<int> z = z_func(temp);
    vector<int> occur;
    for (int i = 0; i < z.size(); i++){
        if(z[i] == pat.size()){
            occur.push_back(i - pat.size()-1);
        }
    }

    return occur;
}

int main(){
    string s,t;
    cin >> s;
    cin >> t;

    vector<int> occur = Z(s, t);
   
   for(auto i: occur){
       cout << i << " ";
   }

    return 0;
}
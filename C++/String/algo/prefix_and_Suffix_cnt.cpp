#include <bits/stdc++.h>
using namespace std;

void z_func(vector<int>& z,string s){
    int l = 0, r = 0;
    for(int i = 1; i < s.size(); i++){
        if(i<=r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i+z[i] < s.size() and s[i+z[i]] == s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1 > r){
            r = z[i] + i - 1;
            l = i;
        }
    }
}

vector<pair<int,int>> solve(string s){
    // z-> calculate the prefix start from ith idx 
    int n = s.size();
    vector<int> z(n, 0);
    z_func(z, s);

    int freq[100005];
    memset(freq, 0, sizeof freq);

    //store all occur of z[i] in freq array it tells at every z[i] value having length of common prefix starting from ith idx
    for(auto num: z){
        freq[num]++;
    }

    //take a suffix sum bcoz we want cnt starting from so in this case we want a sum of all value starting from ith to end 
    for (int i = 100002; i >= 0; i--){
        freq[i] += freq[i + 1];
    }

    vector<pair<int, int>> res;
    for (int i = n - 1; i >= 0; i--){
        if(z[i] == n-i){
            int len = n - i;
            int occur = freq[z[i]] + 1;
            res.push_back({len, occur});
        }
    }
    res.push_back({n, 1});
    return res;
}

int main(){
    string s;
    cin>>s;

    vector<pair<int, int>> occur = solve(s);

    for(auto it: occur){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}
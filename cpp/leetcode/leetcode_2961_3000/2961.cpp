#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/double-modular-exponentiation/

/**
 * ((ai^bi % 10)^ci) % mi == target
 */
#define ll long long int

vector<int> getGoodIndices(vector<vector<int>> &variables, int target){
    int n = variables.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        ll a = variables[i][0];
        ll b = variables[i][1];
        ll c = variables[i][2];
        ll d = variables[i][3];
        ll x = 1;
        for (int j = 0; j < b; j++)
        {
            x *= a;
            x %= 10;
        }
        ll y = 1;
        for (int j = 1; j < c; j++){
            y *= x;
            y %= d;
        }
        if(y==(ll)target)
            res.push_back(i);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(4));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 4; j++){
            cin >> v[i][j];
        }
    }
    int target;
    cin >> target;
    vector<int>ans = getGoodIndices(v, target);

    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
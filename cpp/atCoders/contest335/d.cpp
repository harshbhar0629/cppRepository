#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> f(int n){
    vector<vector<int>> v(n, vector<int>(n));
    int cnt = 1;
    int mnr = 0, mnc = 0, mxr = n - 1, mxc = n - 1;

    while(mnr <= mxr and mnc <= mxc){
        for (int i = mnc; i <= mxc; i++)
        {
            v[mnr][i] = cnt++;
        }
        mnr++;
        for (int i = mnr; i <= mxr; i++)
        {
            v[i][mxc] = cnt++;
        }
        mxc--;
        for (int i = mxc; i >= mnc; i--)
        {
            v[mxr][i] = cnt++;
        }
        mxr--;
        for (int i = mxr; i >=mnr; i--)
        {
            v[i][mnc] = cnt++;
        }
        mnc++;
    }


    return v;
}


int main(){
    int n;
    cin >> n;

    vector<vector<int>> v = f(n);

    for (int i = 0; i<n; i++){
        for (int j = 0; j < n; j++){
            if(i==n/2 and j==n/2){
                cout << "T"<< " ";
            }
            else  cout << v[i][j] << " ";
        }
        cout << endl;
    }

        return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int leftDiagonal[20];
int rightDiagonal[20];
int col[8];

ll solve(int i, const int n, vector<string>& queen){
    if(i==n){
        return 1;
    }
    ll ans =0 ;
    for(int j=0; j<n; j++){
        if(queen[i][j]!='*' and col[j] == -1 and rightDiagonal[i+j] == -1 and leftDiagonal[j-i+n-1] == -1){
            col[j] = 1;
            rightDiagonal[i+j] = 1;
            leftDiagonal[j-i+n-1] = 1;
            ans+=solve(i+1, n, queen);
            col[j] = -1;
            rightDiagonal[i+j] = -1;
            leftDiagonal[j-i+n-1] = -1;
        }
    }
    return ans;
}



ll f(int n, vector<string>& queen){
    memset(leftDiagonal, -1, sizeof leftDiagonal);
    memset(rightDiagonal, -1, sizeof rightDiagonal);
    memset(col, -1, sizeof col);
    return solve(0, n, queen);
}


int main(){
    int n = 8;
    vector<string>v(n, string(n,'.'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }


    cout<<f(n, v);

    return 0;
}
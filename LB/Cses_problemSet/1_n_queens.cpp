#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1624


#define ll long long int

bool isPlaceQueen(int i, int j, int n, vector<string>& queen){
    // checking left diagonal
    for(int r=i, c=j; r>=0 and c>=0; r--, c--){
        if(queen[r][c] == 'Q') return false;
    }

    //checking right diagonal
    for(int r=i, c=j; r>=0 and c<n; r--, c++){
        if(queen[r][c] == 'Q') return false;
    }

    // checking vertically
    for(int r=i; r>=0; r--){
        if(queen[r][j] == 'Q') return false;
    }

    return true;
}



ll f1(int i, int n, vector<string>&queen){

    if(i==n){        
        return 1;
    }
    ll ans = 0;

    for(int j=0; j<n; j++){
        if(queen[i][j]=='*'){
            continue;
        }
        if(isPlaceQueen(i, j, n, queen)){
            queen[i][j] = 'Q';
            ans+=f1(i+1, n, queen);
            queen[i][j] = '.';
        }
    }
    return ans;
}



ll f(int n, vector<string>& queen){
    // memset(dp, -1, sizeof dp);
    return f1(0, n, queen);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 8;
   
    vector<string>queen(n,string(n,'.'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>queen[i][j];
        }
    }


    cout<<f(n, queen);

    return 0;
}
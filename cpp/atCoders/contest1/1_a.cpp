#include <bits/stdc++.h>
using namespace std;

void file_i_o(){
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    file_i_o();
    int n;
    cin>>n;
    string res = "";
    for(int i=0; i<n; i++){
        res = res + to_string(n);
    }
    cout<<res<<endl;

    return 0;
}
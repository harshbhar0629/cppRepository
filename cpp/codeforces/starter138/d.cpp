#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1){
            cout << "1";
        }
        else{
            for (int i = 0; i<n-2; i++){
                cout << "3 ";
            }
            cout << "2 " << "1";
        }
        cout << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> qu;
    int k = 1;
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    qu.push(k++);
    int n=qu.size();

    for (int i = 0; i < qu.size(); i++){
        int x = qu.front();
        qu.pop();
        cout << x << "  ";
        qu.push(x);
    }
    cout << endl;

    cout << "now element remove acoording to zero based indexing \n";

    for (int i = 0; i < n; i++){
        if (i % 2 != 0){
            int x = qu.front();
            qu.push(x);
        }
        qu.pop();       
    }

    for (int i = 0; i < qu.size(); i++) {
        int x = qu.front();
        qu.pop();
        cout << x << "  ";
        qu.push(x);
    }
    cout << endl;

    return 0;
}
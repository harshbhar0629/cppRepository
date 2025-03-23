#include <bits/stdc++.h>
using namespace std;
//  ques: print array in recursion
//  pre, in , post

// => sedhe sedhe pre work
// 0,1,2...
void printArr(int i, vector<int>& v){
    if(i==v.size()){
        // index out of bound ka error
        return;
    }

    // pre work call s pehle wala kam
    cout << v[i] << " ";
    printArr(i + 1, v);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    printArr(0, v);

    return 0;
}
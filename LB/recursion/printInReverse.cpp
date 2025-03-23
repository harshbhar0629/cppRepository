#include <bits/stdc++.h>
using namespace std;
// ques print array in reverse order in recursion
// post work 0...n
// pre 0...n

void printReverse(int idx, vector<int>& v){
    //1000 => 1000 bar vector create hoga , by ref same memory add p work
    if(idx==v.size()){
        return;
    }

    printReverse(idx+1, v);
    //  work
    cout << v[idx] << " ";
}

//0 ->1 -> 2->3->4->5 // return
// 5,->4 , 3 ,2 , 1 // post work

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    printReverse(0, v);

    return 0;
}
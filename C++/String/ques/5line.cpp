#include <bits/stdc++.h>
using namespace std;
int f(string s)
{
    int r = 0;
    stringstream ss(s);

    ss >> r;
    return r;
}

// bool cmp(int a ,int b){
//     return a>b;
// }

int main()
{

    int n ;
    cin>>n;

    cout<<"print: "<<__builtin_popcount(n);
    // int v[7] = {1, 2, 3, 4, 7, 6, 5};
    // for (int i = 0; i < 7; i++)
    // {
    //     cout << v[i] << "  ";
    // }
    // cout << endl;

    // sort(v, v+7);

    // for (int i = 0; i < 7; i++)
    // {
    //     cout << v[i] << "  ";
    // }
    // cout << endl;

    // string s;
    // getline(cin,s);
    // // cout<<f(s);
    // stringstream ss(s);
    // string t;
    // while(ss>>t){
    //     reverse(t.begin(),t.end());
    //     cout<<t<<endl;
    // }

    // 4193 with words
}
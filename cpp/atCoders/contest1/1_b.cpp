// https://atcoder.jp/contests/abc333/tasks/abc333_b
#include <bits/stdc++.h>
using namespace std;

void file_i_o(){
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    file_i_o();
    char s1, s2, t1, t2;
    cin>>s1>>s2;
    cin>>t1>>t2;
    vector<vector<int>>res= {{0,1,2,2,1}, {1,0,1,2,2}, {2,1,0,1,2}, {2,2,1,0,1}, {1,2,2,1,0}};

    int idx1 = s1-'A';
    int idx2 = s2-'A';
    int idx3 = t1-'A';
    int idx4 = t2-'A';

    if(res[idx1][idx2] == res[idx3][idx4] || res[idx2][idx1] == res[idx4][idx3]){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    return 0;
}
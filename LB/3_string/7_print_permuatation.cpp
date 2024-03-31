#include <bits/stdc++.h>
using namespace std;

vector<string>ans;

void f(string &s, int l, int h){
    if(l==h) {
        ans.push_back(s);
        return;
    }
    for(int i=l; i<=h; i++){
        swap(s[i],s[l]);
        f(s, l+1, h);
        swap(s[i], s[l]);
    }
}

int main(){
    string s;
    cin>>s;
    f(s,0,s.size()-1);

    for(auto str: ans){
        cout<<str<<endl;
    }
    

    return 0;
}
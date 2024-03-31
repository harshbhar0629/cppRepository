#include <bits/stdc++.h>
using namespace std;
// void f1(string s,string ans,int i){

//     if(i==s.size()) {
//         cout<<ans;
//         return;
//     }
//     char ch=s[i];

//     if(s[i]!='a'){
//         ans+=ch;
//     }
//     f1(s,ans,i+1);
    
// }

void f2(string s,string ans){

    if(s.size()==0) {
        cout<<ans;
        return;
    }

    if(s[0]!='a'){
        ans+=s[0];
    }
    f2(s.substr(1),ans);
    
}

int main(){

    string s;
    getline(cin,s);
    string ans("");
    f2(s,ans);

}
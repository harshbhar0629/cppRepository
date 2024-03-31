#include<bits/stdc++.h>
using namespace std;

vector<string> sub(string s){
    int n =3;
    vector<string> ans ;
    for(int i=0;i<(1<<n);i++){
        string temp="";
        for(int j=0;j<n;j++){
            if(i & (1<<j)){ 
                temp.push_back(s[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}


int main(){
    string s ="abc";
    vector<string> ans = sub(s);
    for(auto str: ans){
        cout<<str<<endl;
    }
}
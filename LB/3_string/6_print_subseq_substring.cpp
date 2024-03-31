#include <bits/stdc++.h>
using namespace std;

vector<string>ans;
// print all subsequence
void print(string& s,int i, string t){
    if(i>=s.size()){
        ans.push_back(t);
        return;
    }
    print(s,i+1, t+s[i]);
    print(s,i+1, t);
}

// print all substring

void subString(string& s, int i, string t){
    if(i>=s.size()){
        ans.push_back(t);
        return;
    }
    subString(s,i+1,t);
    if(t.size()==0 || t.back() == s[i-1]){
        subString(s, i+1, t+s[i]);
    }
}


int main(){
    string s;
    cin>>s;

    // print(s,0,"");
    subString(s,0,"");

    for(auto it: ans){
        cout<<it<<endl;
    }

    return 0;
}
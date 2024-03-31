#include<bits\stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    //string t("");
    stringstream ss(s);
    vector<string>v;
    string temp;
    while(ss>>temp){
        v.push_back(temp);
    }
    temp="";
    int n=v.size();
    if(n==1){
        cout<<v[0];
        return 0;
    }
    string last=v[n-1],first=v[0];
    for(int i=0;i<first.size();i++){
        if(first[i]==last[i]){
            temp+=first[i];
        }
        else break;
    }
    cout<<temp;

    return 0;
}
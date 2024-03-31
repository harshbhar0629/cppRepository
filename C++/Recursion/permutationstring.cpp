#include<bits/stdc++.h>
using namespace std;

void f2(string s,string ans,vector<string>&v){

    if(s.size()==0){
       v.push_back(ans);
        return;
    }
    for(int i=0;i<s.size();i++){
         char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        f2(ros,ans+ch,v);

    }
}

int main(){
    string s("abc");
    
    vector<string>v;
    f2(s,"",v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

}
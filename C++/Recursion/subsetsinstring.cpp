#include<bits/stdc++.h>
using namespace std;
// print onlyyyyyyyy.....
void f1(string s,string ans,int i){

    if(s.size()==i){
        cout<<ans<<endl;
        return;
    }
     f1(s,ans,i+1);
    f1(s,ans+s[i],i+1);
   
}

// store and print into main functionnnnnnnn.........
void f2(string s,string ans,int i,vector<string>&v){

    if(s.size()==i){
       v.push_back(ans);
        return;
    }
     f2(s,ans,i+1,v);
    f2(s,ans+s[i],i+1,v);
   
}

int main(){
    string s("abc");
    // f1(s,"",0);
    vector<string>v;
    f2(s,"",0,v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

}
#include<bits/stdc++.h>
using namespace std;
void f(string s,string ans,int i,bool flag){
    if(i==s.size()){
        cout<<ans<<endl;
        return;
    }
    if(i==s.size()-1){
        
        if(flag)
        f(s,ans+s[i],i+1,true);
          f(s,ans,i+1,true);
          return;
    }
    else if(s[i]==s[i+1]){
        
        if(flag)
         f(s,ans+s[i],i+1,1);
          f(s,ans,i+1,false);
    }
    else{
        if(flag)
         f(s,ans+s[i],i+1,true);
            
          f(s,ans,i+1,true);
    }
}
int main(){
    string s("aabc");
    f(s,"",0,1);
}
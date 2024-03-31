#include<bits/stdc++.h>
using namespace std;
// print onlyyyyyyyy.....
void f1(string s,string ans,int i,vector<string>&v,bool flag){

    if(s.size()==i){
        v.push_back(ans);
        return;
    }
    if(i==s.size()-1){
        if(flag) 
          f1(s,ans+s[i],i+1,v,true);
         
         f1(s,ans,i+1,v,true);
        return;
    }

    if(s[i]==s[i+1]){
       if(flag)
         f1(s,ans+s[i],i+1,v,true);
        
         f1(s,ans,i+1,v,false);
    }
    else{ 
        if(flag) 
         f1(s,ans+s[i],i+1,v,true); 
          
            f1(s,ans,i+1,v,true);
      
    }
}

int main(){
    string s("aac");
    // f1(s,"",0);
    vector<string>v;
    f1(s,"",0,v,true);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

} 
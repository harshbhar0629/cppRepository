#include<iostream>
using namespace std ;
void f(string s,int i,bool arr[],string ans){
    if(i==s.length()){
        cout<<ans<<endl;
        return ;
    }
    if(arr[s[i]-'a']){
        f(s,i+1,arr,ans);
    }
    else{
        ans+=s[i];
        arr[s[i]-'a']=true;
        f(s,i+1,arr,ans);
    }
}
int main(){
    string s;
    getline(cin,s);
    bool arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    f(s,0,arr, "");

}
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int f(string &s){
    int n=s.size();
    if(n==1) return -1;
     int x=0,l=0;
    vector<int>v1(26,-1);
    vector<int>v2(26,-1);
    for(int i=0;i<n;i++){
        if(v1[s[i]-'a']==-1){
            v1[s[i]-'a']=i;
        }
        else {
            // v2[s[i]-'a']=i-v1[s[i]-'a'];
            l=i-v1[s[i]-'a'];
            x=max(l,x);
        }    
    }
   
    // for(int i=0;i<v2.size();i++){
    //     x=max(v2[i],x);
    // }
    return --x;

}

int main(){
    string s;
    cin>>s;

    cout<<f(s);
}
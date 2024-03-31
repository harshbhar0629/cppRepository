#include<bits./stdc++.h>
using namespace std;

bool isAnagram(string s , string t){
    unordered_map<char,int> mp;
    
    for(char ch: s){
        mp[ch]++;
    }

    for(char ch:t){
        if(mp.find(ch) == mp.end()) return false;
        else  mp[ch]--;
    }

    for(auto it: mp){
        if(it.second!=0) return false;
    }
    
    return true;
    
}

int main(){
    string s,t;
    cout<<"enter two string: ";
    cin>>s>>t;

    cout<< (isAnagram(s,t)? "yes" : "no" )<<endl;
}
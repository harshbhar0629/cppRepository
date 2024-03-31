#include<bits\stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int arr[26]={0};
    int mx=0;
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(mx<arr[i]) mx=arr[i];
    }
    for(int i=0;i<26;i++){
        if(arr[i]==mx){
            cout<<char(i+97)<<"   "<<mx<<endl;
        }
    }
}
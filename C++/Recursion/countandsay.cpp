#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n){
       if(n==1) return "1";
        string s=countAndSay(n-1);
        int count=1;
        string str="";
        char ch=s[0];
        for(int i=1;i<s.length();i++){
            char dh=s[i];
            if(ch==dh){
                count++;
            }
            else{
                str += ((to_string)(count)+ch);
                count=1;
                ch=dh;
            }
        }
            str += ((to_string)(count)+ch);
            return str;
  

}

int main(){
    int n=4;
    cout<<countAndSay(n);
    // string s=count(n);
    // cout<<s;
}
#include<bits/stdc++.h>
using namespace std;
bool f(string &s,int i,int j){
    if(i>j) return true;
    if(s[i]!=s[j]) return false;
    // i++,j--;
    f(s,i+1,j-1);
    
}

int main(){
    string s;
    getline(cin,s);
    if(f(s,0,s.length()-1)){
        cout<<"palindrome";
    }
    else cout<<"not palindrome";
    

}
#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int i){
    if(i>s.size()-1-i) return true;
    if(s[i]!=s[s.size()-1-i]) return false;
    return ispalindrome(s,i+1);

}
int main(){
    string s="aaba";
    cout<<ispalindrome(s,0);
}
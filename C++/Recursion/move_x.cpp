#include<iostream>
using namespace std;
string f(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ros=f(s.substr(1));
    if(s[0]=='x'){
        return ros+ch;
    }
    else return ch+ros;
}
int main(){
    string s;
    getline(cin,s);
    cout<< f(s);
}
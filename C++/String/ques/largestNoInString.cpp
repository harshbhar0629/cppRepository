#include<bits\stdc++.h>
using namespace std;
int main(){
    string s[7];
    for(int i=0;i<7;i++){
        cin>>s[i];
    }
    int x=stoi(s[0]);
    string ms;
    for(int i=0;i<7;i++){
        int y=stoi(s[i]);
        if(x<y){
            x=y;
            ms=s[i];
        }
    }
    cout<<ms<<"  "<<x;

    return 0;
}
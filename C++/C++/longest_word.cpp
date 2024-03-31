#include<iostream>
using namespace std;
int main(){
    // char str[30];
    // cin.getline(str,30);
     string s;
     getline(cin,s);
    cin.ignore();
    int i=0,clen=0,mxst=0,mxlen=0,st=-1 ;
    while(1){
      if(s[i]==' '|| s[i]=='\0'){
        if(mxlen<clen){
            mxlen=clen;
           mxst=st;
        }
        clen=0,st=i+1;
      }
      else clen++;

      if(s[i]=='\0') break;
      i++;

    }
    for(int i=0;i<mxlen;i++){
        cout<<s[i+mxst];
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

    string intToRoman(int n) {
        string s("");
        while(n>=1000){
            s+='M';
            n=n-1000;
        }
        while(n>=500){
            s+='D';
            n= n-500;
        }
         while(n>=100){
            s+='C';
            n= n-100;
        }
         while(n>=50){
            s+='L';
            n= n-50;
        }
         while(n>=10){
            s+='X';
            n=n-10;
        }
        while(n>=5){
            s+='V';
            n=n-5;
        }
        while(n>=1){
            s+='I';
            n=n-1;
        }
        return s;
    }
int main(){
    int n;
    cin>>n;
    cout<<intToRoman(n);
}
/*
            if(n>=1000){
                int x= n/1000;
                while(x--){
                    s+='M';
                }
                n= n- x*1000;
            }
            else if(n>=500){
                int x= n/500;
                while(x--){
                    s+='D';
                }
                n= n- x*500;
            }
            else if(n>=100){
                int x= n/100;
                while(x--){
                    s+='C';
                }
                n= n- x*100;
            }
            else if(n>=50){
                int x= n/50;
                while(x--){
                    s+='L';
                }
                n= n- x*50;
            }
            else if(n>=10){
                int x= n/10;
                while(x--){
                    s+='X';
                }
                n= n- x*10;
            }
            else if(n>=5){
                int x= n/5;
                while(x--){
                    s+='V';
                }
                n= n- x*5;
            }
            else if(n>=1){
                int x= n/1;
                while(x--){
                    s+='C';
                }
                n= n- x*1;
            }
*/
#include<iostream>
using namespace std;

class rectangle{
public:
        int r; 
        int l;
        rectangle(){
            l=0;
            r=0;
        }
};
int main(){
    rectangle a;
    cout<<a.r<<endl<<a.l;
}
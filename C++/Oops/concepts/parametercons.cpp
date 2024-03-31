#include<bits/stdc++.h>
using namespace std;
class btech{
public:
    int x,y;
    btech(){
        x=9,y=5;
    }

};
int main(){
    btech b1;
    b1.x=3;//constructor value can be changed
    cout<<b1.x<<endl<<b1.y;
}
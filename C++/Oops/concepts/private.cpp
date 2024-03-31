#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class insta {
// if we don't provide acess modifiers by default it is private..

    int a;
    int speed;
    public:
    int s(){
      return speed; 
    }
    int geta(){
      return a; 
    }
     void seta(int s){
        speed=s;
    }
    void b(int s){
        a=s;
    }
   

};

int main(){
    insta id;
    id.seta(55);
    id.b(67);
     cout<< id.geta()<<endl;
    cout<< id.s();

   
}
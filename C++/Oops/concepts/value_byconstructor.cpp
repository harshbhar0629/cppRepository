#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class rect {
         rect(){
            cout<<"constructor called";
         }

public:
     int a;//data member
     int b;
        // constructor
         rect(int l ,int b){ //member function
           a=l;
           this->b=b;
         }

};

int main(){
    cout<<"hi"<<endl;
    rect r(3,4);
    cout<<"hello"<<endl;
     cout<<r.a<<endl<<r.b<<endl;
   // rect v;
  


}
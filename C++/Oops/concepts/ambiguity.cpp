#include<bits/stdc++.h>
using namespace std ;
class A{
public:
    void fun(){
        cout<<"class A func called"<<endl;
    }
};
class B{
public:
    void fun(){
        cout<<"class B fun called "<<endl;
    }
};
class C:public A,public B{
public:
};
int main(){
    C obj;
    obj.A::fun();
    obj.B::fun();

}
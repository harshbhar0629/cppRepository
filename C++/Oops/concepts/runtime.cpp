#include<bits/stdc++.h>
using namespace std ;
class parent{
public:
    void fun(){
        cout<<"parent fun called"<<endl;
    }
};
class child:public parent{
public:
    virtual void fun(){
        cout<<"child fun called"<<endl;
    }
};
int main(){
    child c;
    c.parent::fun();
}
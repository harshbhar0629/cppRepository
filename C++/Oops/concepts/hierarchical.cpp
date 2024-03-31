#include<bits/stdc++.h>
using namespace std;
// multiple child class inherits the prop of same class
class parent{
public:
    int age ;
    int weight;
    void f(){
        cout<<"ahah"<<endl;
    }
};
class child:public parent{
public:
    string name;
     void h(){
        cout<<"hn thik hai"<<endl;
    }
};
class grand:public parent{
public:
     string gender;
     void state(){
        cout<<"UP"<<endl;
     }
};
int main(){
    grand g;
    g.age=12;
    g.weight=45;
    g.gender="female";
    g.state();
    g.f();
    cout<<g.age<<endl;
    cout<<g.weight<<endl;
    cout<<g.gender<<endl;
    cout<<endl;
    child c;
    c.age=16;
    cout<<c.age<<endl;
    c.h();
    c.f();
    c.weight=56;
    c.name="guru randhawa";
    cout<<c.weight<<endl;
    cout<<c.name<<endl;

}
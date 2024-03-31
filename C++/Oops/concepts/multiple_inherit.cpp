#include<bits/stdc++.h>
using namespace std;
// child class inherits the prop of two classes
class parent{
public:
    int age ;
    int weight;
    void f(){
        cout<<"ahah"<<endl;
    }
};
class child{
public:
    string name;
     void h(){
        cout<<"hn thik hai"<<endl;
    }
};
class grand:public parent,public child{
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
    g.name="moti";
    g.state();
    g.f();
    g.h();
    cout<<g.age<<endl;
    cout<<g.name<<endl;
    cout<<g.weight<<endl;
    cout<<g.gender<<endl;
}
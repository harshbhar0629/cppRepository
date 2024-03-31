#include<bits/stdc++.h>
using namespace std;

#include"current_directives.cpp"


int main(){
    hero h1;
    cout<<sizeof(h1);
    cout<<"enter name";
    cin.getline(h1.name,100);
    cout<<"enter health";
    cin>>h1.health;
    cout<<"enter level";
    cin>>h1.level;
    
    cout<<endl<<" name ->"<<h1.name;
    cout<<endl<<" health ->"<<h1.health;
    cout<<endl<<" level ->"<<h1.level;

}


/*
class class_name{
// public:
    // string class_properties;

};
int main(){
    class_name object;
    cout<<sizeof(object);  //ans-> 1
    cout<<sizeof(object); // when string is not commented then size ->24
    // object.class_properties="harsh";
    // cout<<object.class_properties;
}
*/
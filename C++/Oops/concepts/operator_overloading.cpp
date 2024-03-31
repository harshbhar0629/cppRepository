#include<iostream>
using namespace std;
class hero{
public:
    string name;
    int age;
    hero(){
        cout<<"constructor called"<<endl;
    }
    void setname(string s){
        name=s;
    }
    string getname(){
        return name;
    }
    void setage(int a){
        age=a;
    }
    int getage(){
        return age;
    }
    bool operator ==(hero &h2){
        if(name ==h2.name && age==h2.age) return true;
        else return false;
    }

};
int main(){
    hero h1;
    h1.setage(22);
    h1.setname("harsh");
    hero h2;
     h2.setage(22);
    h2.setname("harsh");
    if(h2==h1)
        cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    
}
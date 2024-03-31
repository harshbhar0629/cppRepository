#include<bits/stdc++.h>
using namespace std;
class hero{
private: 
    int health;
public:
    char level;
    char *name;
    hero(){
        cout<<"simple constructor called:"<<endl;
        name=new char[100];
    }
    void setlevel(char l){
        level=l;
    }
    void sethealth(int h){
        health=h;
    }
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void print(){
        cout<<"health : "<<health<<endl;
        cout<<"level : "<<level<<endl;
        cout<<"name : "<<name<<endl;
    }
    void setname(char name[]){
        strcpy(this->name,name);
    }
    // copy constructor
    hero(hero &h){
        char *ch=new char(strlen(h.name)+1);
        strcpy(ch,h.name);
        this->name=h.name;
        health=h.health;
        level=h.level;
    }

};
int main(){
    hero h1;
    h1.sethealth(58);
    h1.setlevel('b');
    char name[8]="harsh";
    h1.setname(name); 
    h1.print();
    hero h2(h1);
    h2.print();
    h1.name[0]='a';
    h1.print();
    h2.print();
}
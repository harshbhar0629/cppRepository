#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class fruit {
public: 
    string color;
    string name;
    string taste;
    int amount;

};

int main(){
    fruit a;
    a.amount=70;
    a.color="yellow";
    a.name="mango";
    a.taste="gud";
    cout<<a.amount<<endl;
    cout<<a.name<<endl;
    cout<<a.color<<endl;
    cout<<a.taste<<endl;

//    dynamically
    // fruit *b=new fruit();
    fruit *b=new fruit;
     b->amount=80;
     b->color="orange";
     b->name="orange";
     b->taste="well";
     cout<<b->amount<<endl;
     cout<<b->name<<endl;
     cout<<b->color<<endl;
     cout<<b->taste<<endl;
    
   
}
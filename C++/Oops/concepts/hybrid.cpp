#include<bits/stdc++.h>
using namespace std;
// child class inherits the prop of two classes
class parent{   
public:
    parent(){
        cout<<"parent"<<endl;
    }
};
class child:public parent{
public:
   child(){
    cout<<"child"<<endl;
   }
};
class grand:public parent{
public:
    grand() {
        cout<< "grand"<<endl;
    }
};
class chota:public grand{
public:
    chota(){
        cout<< "chota"<<endl;
    }
};
int main(){
    chota c;
    cout<<endl;    
    child c1;
}
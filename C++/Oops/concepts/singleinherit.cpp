#include<bits/stdc++.h>
using namespace std;
// child inherits the prop. of parent 
class parent{
public:
     int age;
     string name;
     void speaking(){
        cout<<"hn thik h"<<endl;
     }
};
class child:public parent{
public:

};
int main(){
    child c;
    c.age=12;
    c.name="garshju";
    c.speaking();
    cout<<c.age<<endl;
    cout<<c.name<<endl;
}
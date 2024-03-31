#include<iostream>
using namespace std;
class doubly{
public:
    int x,y;
    doubly(int x,int y){
        // x=x,y=y;   // -> isme ans garbage ayega
        //isme x khud ko h apni value de rha h same as for y
        // if we have existing variable of same name then use "this" keyword it hold address of existing variable
        this ->x=x;
        this->y=y;
    }
    // doubly(const doubly &r){
    //     x=r.x;
    //     y=r.y;

    // }

    doubly(){

    }

};
int main(){
    doubly d(3,4);
    doubly f=d;
    // doubly f=d;
    // doubly f(d);     //valid also
    cout<<f.x<<endl<<f.y;
    cout<<f.x<<endl<<f.y;
}
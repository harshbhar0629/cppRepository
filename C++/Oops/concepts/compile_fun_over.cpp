#include<bits/stdc++.h>
using namespace std;
class A{
public:
    void fun(){
        cout<<"class A ccalled"<<endl;
    }
    void fun(int x){
        cout<<"one para func"<<endl;
    }
    void fun(int x,int y){
        cout<<"with two para func"<<endl;
    }
    void fun(double x){
        cout<<"double called"<<endl;
    }
};
int main(){
    A obj;
    obj.fun();
    obj.fun(2);
    obj.fun(2.4);
    obj.fun(2,3);
}
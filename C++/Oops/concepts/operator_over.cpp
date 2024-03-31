#include<bits/stdc++.h>
using namespace std ;
class A{
public:
    int real;
    int img;
    A(){

    }
    A(int x,int y){
        real=x;
        img=y;
    }
   
    A operator +(A &a2){
        A ans(0,0);
        ans.real=real+a2.real;
        ans.img=img+a2.img;
        return ans;
    }


};
int main(){
    A a1(2,5);
    A a2(4,4);
    A a3;
    a3=a1+a2;
    cout<<"real is: "<<a3.real<<endl<<"Img is: "<<a3.img<<endl;
}
#include<bits/stdc++.h>
using namespace std;
// #pragma pack(1) // __attribute__((__packed__)) are the two ways to reduce the actual size of object..
// class A{
// public:
//    A(){
//     cout<<"constructor called a"<<endl;
//    }
// };
// class B{
//     // A obj1;
// public:
//     B(){
//         cout<<"constructor called b"<<endl;
//     }
   
// };
// class C:public A,public B{
//     // A obj1;
// public:
//     C(){
//         cout<<"constructor called c"<<endl;
//     }
   
// };
class a{
    public:
    int a;
    int b;
};
int main(){
    a a1;
    a a2;
    a2=a1;
    a1.a=9;
    a1.b=8;
    cout<<a2.a<<"  "<<a2.b;
    // C c;
    // B obj1;
    // cout<<"space"<<endl;
    // B obj2;
    return 0;
}
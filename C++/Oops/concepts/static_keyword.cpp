#include<iostream>
using namespace std;
class hero{
public:
    static int time;
};
int hero::time=5;
int main(){
    cout<<hero::time;
} 
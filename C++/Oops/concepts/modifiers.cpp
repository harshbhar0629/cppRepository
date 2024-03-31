#include<bits/stdc++.h>      
using namespace std;
class harsh{
private:
 int x;
protected: 
    int y;     
public:
    int z;

};
class c1:public harsh{
    // class c1 inherits the prop. harsh by using public modifiers
    // public acessible 
    // protected is behave as a protected means not acessible
    // private behave as a private not acessible
}
class c2:protected harsh{
    // class c2 inherits the prop. harsh by using protected modifiers
    // public acessible 
    // protected is behave as a protected but acessible 
    // private behave as a private not acessible
}
class c3:private harsh{
    // class c3 inherits the prop. harsh by using private modifiers
    // public not acessible 
    // protected is behave as a protected not acessible 
    // private behave as a private not acessible
}
int main(){
    //
}
#include<bits/stdc++.h>      
using namespace std;
class harsh{
    int x;
public:
    void set(int y){
        x=y;
    }
    int get(){
        return x;
    }
        
};
int main(){
    harsh h;
    h.set(3);
    cout<<h.get();
}
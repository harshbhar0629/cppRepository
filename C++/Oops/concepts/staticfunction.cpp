#include<iostream>
using namespace std;
class hero{
public:
    int age;
    string name;
    static int time;
    void show(){
        cout<<this->name<<endl;
        cout<<name<<endl;
        cout<<age<<endl;
    }
    int static random(){
        // cout<<this->name<<endl;
        // cout<<name<<endl;
        // cout<<age<<endl;
       return time;
    }
};
// / static function only acess static member only...
int hero::time =5;
int main(){
    hero h={11,"haha"};
    h.show();
    cout<<hero::random();
} 
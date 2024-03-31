#include <bits/stdc++.h>
using namespace std;

class Stud final{
public:
    int rno;
    string name;
    double marks;
    Stud(){}
    Stud(int rno, string name, double marks){
        this->rno = rno;
        this->marks = marks;
        this->name = name;      
    }
    Stud(Stud& s){
        this->rno = s.rno;
        this->marks = s.marks;
        this->name = s.name;
    }
    void replace(string name){
        this->name = name;
    }
    ~Stud(){
        cout << "Destructor Called:\n";
        cout << this->name << "\n";
    }
};


int main(){
    int const a = 2;
    int  final = 2;
    Stud s1(1, "harsh1", 1.2);
    // cout << s1.name;

    Stud s(1, "harsh2", 1.2);
    Stud* ss = new Stud(s);
    s.name = "gwifuqds";
    // cout << typeid(ss).name() << "\n";

    return 0;
}
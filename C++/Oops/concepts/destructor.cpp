#include<iostream>
using namespace std;
class dest{
  int a;
public:
    ~dest(){
      cout<<"destructorcalled  "<<a<<endl;
    }

    dest(int a){
      this->a = a;
      cout<<"construcorcalled  "<<a<<endl;
    }
    
};
int main(){
  dest d(1);
  dest r(2);
  dest b(3);
  dest *a=new dest(4);//destructor not called in dynamically but in case of statically it called auomatically 
  delete a;
}    
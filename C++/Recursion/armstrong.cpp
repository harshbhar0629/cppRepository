#include<iostream>
using namespace std;
int digit(int n,int d){
 if(n==0) return d;
  digit(n/10,++d);

}
int power(int n,int d){
    if(d==0) return 1;
    return n*power(n,d-1);
}
int armstrong(int n,int d){
    if(n==0) return 0;
    return power(n%10,d)+armstrong(n/10,d);
}

int main(){
    int n;
     cin>>n;
     int d=0;
     d=digit(n,d);
     if(n==armstrong(n,d)) cout<<"armstrong number";
     else cout<<"not armstrong number";
}
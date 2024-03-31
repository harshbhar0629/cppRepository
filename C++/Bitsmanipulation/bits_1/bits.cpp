#include<iostream>
using namespace std;
int setbits(int n,int pos){
    return (n| (1<<pos));
}
int clearbit(int n,int pos){
    int f=1<<pos;
    f=~f;
    return (n&f);
}
int update(int n,int pos,int value){
    int m=~(1<<pos);
    n=n&m;
    return (n|(value<<pos)); 
}
int power(int n){
    return ((n&(n-1))==0);
}
int countones(int n){
    int count=0;
    while(n){
        n=n&n-1;
        count++;
    }
    return count;
}
int main(){
int n;
cin>>n;
cout<<countones(n);
return 0;
}
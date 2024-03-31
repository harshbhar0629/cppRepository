#include<iostream>
using namespace std;
void tofhanoi(int n,char s,char d,char sp){
    if(n==1) cout<<s<<" to "<<d<<endl;
    else{
        tofhanoi(n-1,s,sp,d);
        tofhanoi(1,s,d,sp);
        tofhanoi(n-1,sp,d,s);
    }
}
int main(){
    int n;
    cout<<" ente number of slides";
    cin>>n;
    tofhanoi(n,'A','C','B');
    return 0;
}
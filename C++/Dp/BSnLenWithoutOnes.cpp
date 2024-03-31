#include <iostream>
using namespace std;

int count=0;
void binaryString(string s , int n){
    if(s.size()==n) {
        count++;
        return;
    }
    if(s.size()==0){
        binaryString(s+'0',n);
        binaryString(s+'1',n);
    }
    else if(s.back()=='1'){
        binaryString(s+'0',n);
    }
    else{
        binaryString(s+'0',n);
        binaryString(s+'1',n);
    }
}

int bstring(int n){
    if(n==1 || n==2) return n+1;
    return bstring(n-1)+bstring(n-2);
}

int main(){
    int  n;
    cin>>n;
    // binaryString("",n);
    // cout<<count;

    cout<<bstring(n);

    return 0;
}
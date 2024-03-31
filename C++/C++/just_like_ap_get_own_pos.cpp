#include<iostream>
using namespace std;
int print(int n, int m,int d, bool flag){
    cout<<"  "<<n;
    if(n==m && flag == false) return 0;
    if(flag){
        if(n-d>0) return print(n-d,m,d,true);
        else{
            return print(n-d,m,d,false);
        }
    }
    else{
        return print(n+d,m,d,false);
    }
}
int main(){
    int n,d;
    cin>>n>>d;
    print(n,n,d,1);
    return 0;
}
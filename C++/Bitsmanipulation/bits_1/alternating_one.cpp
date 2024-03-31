#include<bits/stdc++.h>
using namespace std;

 bool hasAlternatingBits(int n) {
        bool flag=false;
        if(( n & 1 ) > 0){
            flag=true;
        }
        while(n){
            if(flag && (n & 1)<=0){
                 return false;
            }
            else if(!flag && n&1==1){
                return false;
            }
            flag = !flag;
            n= n>>1;
        }
        return true;
    }

int main(){
    cout<<(hasAlternatingBits(5));
    return 0;
}
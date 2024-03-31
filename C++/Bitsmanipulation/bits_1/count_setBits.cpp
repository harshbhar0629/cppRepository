#include<bits/stdc++.h>
using namespace std;
int count_set_bit(int n){
    return __builtin_popcount(n);
}
int count_set_bit2(int n){
    int count=0;
    while(n){
        count++;
        n= ( n & (n-1));
    }
    
    return count;
}
int main(){
    // int n;
    // cin>>n;
    // // cout<<count_set_bit(n)<<endl;
    // cout<<count_set_bit2(n);
    int a=(-1<<(2));
    cout<<a;

}
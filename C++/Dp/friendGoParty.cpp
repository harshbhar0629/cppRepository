#include <iostream>
using namespace std;

int waysToGoParty(int n ){
    // base case
    if(n==1 || n==2) return n;
    return waysToGoParty(n-1)+ (n-1)*waysToGoParty(n-2);
}

int main(){
    
    int n ;
    cin>>n;
    cout<<waysToGoParty(n)<<endl;

    return 0;
}
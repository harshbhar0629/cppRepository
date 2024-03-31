#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    auto sum = [](int x) -> int
    {
        if(x<=1){
            return x;
        }
        return x + sum(x - 1);
    };

    while(n>0){
        cout <<"Sum: " << sum(n) << "\n";
    }
}

int main(){
    int n;
    cin>>n;

    fun(n);

    return 0;
}
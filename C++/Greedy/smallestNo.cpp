#include<bits/stdc++.h>
using namespace std;

void makeSmallestNumber(int digit,int sum){
    if(9*digit < sum){
        cout<<"-1";
        return ;
    }

    vector<char>v(digit, '0');
    int i;
    sum--;
    for(i = digit-1 ; i>=0 ; i--){
        if(sum<9) break;
        v[i]='9';
        sum-=9;
    }
    if(v[i]=='0' and i==0){
        sum++;
        v[i]=char(sum+'0');
    }
    else{
        v[i] = char(sum+'0');
    }

    if(v[0]=='0'){
        v[0]='1';
    }

    for(int i=0;i<digit;i++){
        cout<<v[i];
    }
}

int main(){
    int sum,digit;
    cin>>digit>>sum;
    // digit =4,sum=22;
    makeSmallestNumber(digit,sum);

    return 0;
}
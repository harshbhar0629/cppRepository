#include<bits/stdc++.h>
using namespace std;

class Solution {

    int lessThanKFib(int num){
        if(num==1 || num==2) return num;
        int sum = 1;
        int a=1,b=0;
        while(sum+a <= num){
            b=a;
            a=sum;
            sum = a+b;
        }
        return sum;
    }

public:
    int findMinFibonacciNumbers(int k) {
        if(k==1) return k;
        int ansCount=0;
        int sum=0;
     
        while(sum!=k){
            sum = sum+ lessThanKFib(k-sum);
            ansCount++; 
        }
        return ansCount;
    }
};

int main(){
   
   return 0;
}
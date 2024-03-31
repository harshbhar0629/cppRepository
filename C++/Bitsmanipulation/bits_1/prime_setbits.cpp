#include<bits/stdc++.h>
using namespace std;
int countPrimeSetBits(int left, int right) {
        int ans_prime=0;
        for(int i=left;i<=right;i++){
            int num=i,count=0;
            while(num){
                num=(num & (num-1));
                count++;
            }
            if(count<2 || (count!=2 && count%2==0)) continue;
            bool flag= true;
            for(int i=2;i<=sqrt(count);i++){
                if(count%i==0){
                    flag= false;
                    break;
                }
            }
            if(flag){
                ans_prime++;
            }
        }
        return ans_prime;
    }
int main(){
    cout<<(countPrimeSetBits(10,15));
    return 0;
}
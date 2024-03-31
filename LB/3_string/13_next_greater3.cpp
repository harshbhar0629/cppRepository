// https://leetcode.com/problems/next-greater-element-iii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int num) {
        vector<int> digit;
        while(num){
            digit.push_back(num%10);
            num/=10;
        }
        int idx = -1;
        int n = digit.size();
        for(int i=1; i<n; i++){
            if(digit[i] < digit[i-1]){
                idx = i;
                break;
            }
        }

        if(idx==-1) return -1;

        reverse(digit.begin(), digit.begin()+idx);

        int midx = idx;

        for(int i = idx; i>=0; i--){
            if(digit[i]>digit[idx]){
                midx = i;
                break; 
            }
        }

        swap(digit[idx], digit[midx]);

        long long int ans = 0;
        for(int i=n-1; i>=0; i--){
            ans = ans*10 + digit[i];
        }
        return ans<=INT_MAX? ans: -1;
    }
};

int main(){
    

    return 0;
}
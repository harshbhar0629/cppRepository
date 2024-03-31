#include <bits/stdc++.h>
using namespace std;

int boyer_moore(vector<int>& nums){
    int num = 0, cnt=0;
    for(auto x: nums){
        if(cnt==0){
            num = x;
        }
        cnt += (x==num)? 1:-1;
    }
    int n = nums.size();
    cnt=0;
    for(int i=0; i<n; i++){
        if(num == nums[i]){
            cnt++;
        }
    }
    if(cnt>n) return num;
    return -1;
}

int main(){
    

    return 0;
}
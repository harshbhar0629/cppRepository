#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/three-consecutive-odds/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        const int n = arr.size();
        int cntOdd = 0;

        for(int i=0; i<n; i++){
            if(arr[i]&1){
                cntOdd++;
            }
            else{
                cntOdd = 0;
            }
            if(cntOdd >= 3){
                return true;
            }
        }

        return false;
    }
};


int main(){
    

    return 0;
}
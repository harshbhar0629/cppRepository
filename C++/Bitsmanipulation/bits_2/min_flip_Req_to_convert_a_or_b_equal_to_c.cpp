#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution{
public:
    int minFlips(int a, int b, int c){
        int cnt = 0;
        for (int i = 0; i < 32; i++){
            int bit_a = (((a >> i) & 1) == 1) ? 1 : 0;
            int bit_b = (((b >> i) & 1) == 1) ? 1 : 0;
            int bit_c = (((c >> i) & 1) == 1) ? 1 : 0;
            if(bit_c == 1){
                cnt += !(bit_a or bit_b);
            }
            else{
                cnt += bit_a + bit_b;
            }
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}
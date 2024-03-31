#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        int xSum = 0;
        for (int i = 0; i < n; i++)
        {
            xSum ^= nums[i];
        }
        k ^= xSum;
        return __builtin_popcount(k);

        int n = nums.size();
        int ans=0;

        for(int i=0; i<31; i++){
            int b = 0;
            for(int j=0; j<n; j++){
                int bit = (nums[j]>>i)&1;
                if(bit == 1){
                    b ^= 1;
                }
            }
            if(b != ((k>>i)&1)) ans++;
        }
        return ans;
    }
};

int main(){
    

    return 0;
}
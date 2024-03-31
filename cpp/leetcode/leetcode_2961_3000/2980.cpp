#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/

class Solution{
public:
    bool hasTrailingZeros(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
                cnt++;
            if (cnt > 1)
                return true;
        }
        return false;
    }
};

int main(){
    


    return 0;
}
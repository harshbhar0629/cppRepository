#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/maximum-and-value-1587115620/1

class Solution
{
    int checkBit(int arr[], int n, int res)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if ((res & arr[i]) == res)
            {
                cnt++;
            }
        }

        return cnt;
    }

public:
    int maxAND(int arr[], int n)
    {
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int cnt = checkBit(arr, n, ans | (1 << i));
            if (cnt >= 2)
            {
                ans = ans | (1 << i);
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
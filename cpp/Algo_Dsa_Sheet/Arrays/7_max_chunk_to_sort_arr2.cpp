#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        // max chunk to break to sort array
        // [0..n] -> [0..i] (ith)element min[i+1..n] if it is lesser or equal to
        // ith element then we found one chunk to spilit arr

        int n = arr.size();
        int prefixMax[n];
        int suffixMin[n];

        // finding previous maxi
        prefixMax[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }

        // finding overall maximum from [i..to..n]
        suffixMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMin[i] = min(suffixMin[i + 1], arr[i]);
        }

        // finding chunk to spilit in large number
        int ans = 1; // always having one chunk if we consider whole array
        for (int i = 0; i < n - 1; i++)
        {
            if (prefixMax[i] <= suffixMin[i + 1])
            {
                ans++;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/max-chunks-to-make-sorted/
 * Constraints:
    n == arr.length
    1 <= n <= 10
    0 <= arr[i] < n
    All the elements of arr are unique.
 *
*/

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        // [0..n] -> max no of chunk to sort arr
        // [i..j] -> sort all element and put in arr and check it is sorted or not
        // cases : [2,0,1,3,5,4,6]
        //         [2,5,1,3,0,4,6]
        // we can't split arr untill a max number exist in previous chunk

        int n = arr.size();
        int maxi = arr[0];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
            if (maxi <= i)
            {
                ans++;
            }
        }

        return max(1, ans);
    }
};

int main(){
    

    return 0;
}
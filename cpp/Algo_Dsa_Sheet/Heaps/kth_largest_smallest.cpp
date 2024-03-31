#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &num : nums)
        {
            if (pq.size() < k)
            {
                pq.push(num);
            }
            else if (pq.top() < num)
            {
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();

        // sort(nums.begin(), nums.end());
        // k %= (nums.size()+1);
        // return nums[nums.size() - k];
    }
    
    int findKthSmallest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (auto &num : nums)
        {
            if (pq.size() < k)
            {
                pq.push(num);
            }
            else if (pq.top() > num)
            {
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();

        // sort(nums.begin(), nums.end());
        // k %= (nums.size()+1);
        // return nums[k-1];
    }
};

int main(){
    

    return 0;
}
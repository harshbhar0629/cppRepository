#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

class Solution
{
public:
    // TC: (NlogN + m * n) -> (m*n) where m is the size of queries and n is the size of nums
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for (auto q : queries)
        {
            if (q[1] < nums[0])
            {
                ans.push_back(-1);
            }
            else
            {
                int max_xor = 0;
                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums[i] <= q[1])
                    {
                        max_xor = max(max_xor, nums[i] ^ q[0]);
                    }
                    else
                    {
                        break;
                    }
                }
                ans.push_back(max_xor);
            }
        }

        return ans;
    }
};

/***************************************************************************************************************/

class Trie
{
public:
    Trie *left;
    Trie *right;
    Trie()
    {
        this->left = this->right = NULL;
    }
};
class Solution
{

    Trie *head = new Trie();

    void insert(int num)
    {
        Trie *curr = head;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if (bit == 0)
            {
                if (curr->left == NULL)
                {
                    curr->left = new Trie();
                }
                curr = curr->left;
            }
            else
            {
                if (curr->right == NULL)
                {
                    curr->right = new Trie();
                }
                curr = curr->right;
            }
        }
    }

    int max_xor(int val)
    {
        Trie *curr = head;
        int ans = 0;
        if (curr->left == NULL and curr->right == NULL)
        {
            return 0;
        }

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((val >> i) & 1);

            if (bit == 1)
            {
                if (curr->left != NULL)
                {
                    ans += (1 << i);
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            {
                if (curr->right != NULL)
                {
                    ans += (1 << i);
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
        }

        return ans;
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    // TC: (nlogn + mlogm + m+n)
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {

        int n = nums.size();
        int m = queries.size();
        for (int i = 0; i < m; i++)
        {
            queries[i].push_back(i);
        }

        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), cmp);
        int i = 0;
        vector<int> ans(m, -1);

        for (auto q : queries)
        {
            int val = q[0];
            int max_val = q[1];
            int idx = q[2];
            while (i < n and nums[i] <= max_val)
            {
                insert(nums[i]);
                i++;
            }
            if (i != 0)
            {
                int xor_val = max_xor(val);
                ans[idx] = xor_val;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
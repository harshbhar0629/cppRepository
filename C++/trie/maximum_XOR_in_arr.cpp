#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

/****************** Approach-1 ************************/
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int XOR = nums[i] ^ nums[j];
                maxi = max(XOR, maxi);
            }
        }

        return maxi;
    }
};

/***************************** Approach-2 **************************************/

class Trie
{
public:
    // left represent 0
    //  right represent 1
    Trie *left;
    Trie *right;
    Trie()
    {
        this->left = this->right = NULL;
    }
};
class Solution
{

    int maxXorPair(Trie *head, int val)
    {
        int curr_xor = 0;
        Trie *curr = head;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (val >> i) & 1;
            if (bit == 0)
            {
                if (curr->right != NULL)
                {
                    curr = curr->right;
                    curr_xor += (1 << i);
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->left != NULL)
                {
                    curr = curr->left;
                    curr_xor += (1 << i);
                }
                else
                {
                    curr = curr->right;
                }
            }
        }

        return curr_xor;
    }

    void insert(Trie *head, int val)
    {
        Trie *curr = head;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (val >> i) & 1;

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

public:
    int findMaximumXOR(vector<int> &nums)
    {

        Trie *head = new Trie();
        int n = nums.size();
        int ans = 0;
        insert(head, nums[0]);

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, maxXorPair(head, nums[i]));
            insert(head, nums[i]);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
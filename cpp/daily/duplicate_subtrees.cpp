#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/duplicate-subtrees/1

class Solution
{
    string f(Node *curr, unordered_map<string, int> &mp, vector<Node *> &ans)
    {
        if (!curr)
        {
            return "*";
        }

        string s = "";
        s += to_string(curr->data) + " ";

        s += f(curr->left, mp, ans);
        s += f(curr->right, mp, ans);

        if (mp[s] == 1)
        {
            // we found a duplicate subtree start from currNode:)
            ans.push_back(curr);
        }

        mp[s]++;
        return s;
    }

public:
    vector<Node *> printAllDups(Node *root)
    {
        vector<Node *> ans;
        unordered_map<string, int> mp;
        f(root, mp, ans);
        return ans;
    }
};

int main(){
    

    return 0;
}
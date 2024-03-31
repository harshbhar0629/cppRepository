#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL) return ans;

    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;

    while (q.size() > 0)
    {
        int size = q.size();
        vector<int> v(size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            int index = leftToRight ? i : size - 1 - i;
            v[index] = temp->val;
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }

        leftToRight = !leftToRight;
        ans.push_back(v);
    }
    return ans;
}

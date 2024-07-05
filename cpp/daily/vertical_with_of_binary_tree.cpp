#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

class Solution
{
    using ll = long long int;
    int mini, maxi;

    void f(Node *root, int i)
    {
        if (!root)
        {
            return;
        }

        mini = min(mini, i);
        maxi = max(maxi, i);
        f(root->left, i - 1);
        f(root->right, i + 1);
    }

public:
    int verticalWidth(Node *root)
    {
        if (!root)
            return 0;
        mini = 1e8, maxi = -1e8;
        f(root, 0);

        return abs(maxi) + abs(mini) + 1;
    }
};

int main(){
    

    return 0;
}
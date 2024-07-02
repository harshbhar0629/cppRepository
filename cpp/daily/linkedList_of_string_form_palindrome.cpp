#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1

// The structure of linked list is the following
struct Node
{
    string data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    bool compute(Node *head)
    {
        string s = "";
        Node *curr = head;
        while (curr)
        {
            s += curr->data;
            curr = curr->next;
        }

        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}
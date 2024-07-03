#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1


struct Node {
    int data;
    struct Node *next;
    Node(int v){
        data = v;
        next = nullptr;
    }
};


class Solution
{
public:
    Node *removeAllDuplicates(struct Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        Node *dummy = new Node(0);
        dummy->next = head;
        head = dummy;

        while (head->next and head->next->next)
        {
            if (head->next->data == head->next->next->data)
            {
                auto t = head->next;
                while (t and t->data == head->next->data)
                {
                    t = t->next;
                }
                head->next = t;
            }
            else
                head = head->next;
        }

        return dummy->next;
    }
};

int main(){
    

    return 0;
}
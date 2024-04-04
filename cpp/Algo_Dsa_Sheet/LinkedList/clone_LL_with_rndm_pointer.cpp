#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int val) {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};


class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        Node *tempH = head;
        Node *deepCopy = new Node(-1);
        Node *tempD = deepCopy;
        // first making deep copy
        while (tempH)
        {
            tempD->next = new Node(tempH->val);
            tempD = tempD->next;
            tempH = tempH->next;
        }

        deepCopy = deepCopy->next;
        tempH = head;
        tempD = deepCopy;
        unordered_map<Node *, Node *> mp;
        while (tempH)
        {
            mp[tempH] = tempD;
            tempH = tempH->next;
            tempD = tempD->next;
        }

        for (auto it : mp)
        {
            tempH = it.first;
            tempD = it.second;
            if (tempH->random)
            {
                Node *random = tempH->random;
                tempD->random = mp[random];
            }
        }

        // return deepCopy;

        Node* tempH = head;
        Node* deepCopy = new Node(-1);
        Node* tempD = deepCopy;
        // first making deep copy
        while(tempH){
            tempD->next = new Node(tempH->val);
            tempD = tempD->next;
            tempH = tempH->next;
        }

        deepCopy = deepCopy->next;
        tempH = head;
        tempD = deepCopy;
        Node* merge = new Node(-1);
        Node* tempM = merge;
        // merging case deep copy and given LinkedList
        while(tempH){
            tempM->next = tempH;
            tempM = tempM->next;
            tempH = tempH->next;

            tempM->next = tempD;
            tempM = tempM->next;
            tempD = tempD->next;
        }

        merge = merge->next;
        tempM = merge;
        Node* temp;

        // handling random case if any node having random then make random as well in deep copy
        while(tempM){
            temp = tempM->next;
            if(tempM->random) temp->random = tempM->random->next;
            tempM = tempM->next->next;
        }

        tempM = merge;
        Node* t1 = new Node(1);
        Node* ans = new Node(1);
        temp = ans;
        while(tempM){
            t1->next = tempM;
            t1 = t1->next;
            tempM = tempM->next;

            temp->next = tempM;
            tempM = tempM->next;
            temp = temp->next;
        }
        t1->next = NULL;
        temp->next = NULL;
        return ans->next;
    }
};

int main(){
    

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

int main(){
    Node a(10);
    Node b(20);
    Node c(33);
    a.next = &b;
    b.next = &c;
    // print the VALUE OF Next node
    cout<<a.next->next->val<<endl;
    cout<<b.next->val<<endl;
    return 0;
}
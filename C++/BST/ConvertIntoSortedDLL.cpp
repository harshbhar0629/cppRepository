#include<bits/stdc++.h>
#include"constructTreeFromInorder.cpp"

void convertIntoDLL(Node* root ,Node* &head){
    if(root==NULL) return ;

    // right subtree into DLL
    convertIntoDLL(root->right,head);

    // attach root node in right
    root->right = head;
    // prev or left pointer attach to our root 
    if(head) head->left = root;
    // update head
    head = root;

    // left subtree into DLL
    convertIntoDLL(root->left,head);

}

void printLinkedList(Node* head){
    Node* temp = head;
    cout<< "Sorted Linked List : ";
    while(temp){
        cout<<temp->val<<"  ";
        temp=temp->right;
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    Node* root = constructTreeFromInorder(arr,0,7);
    Node* head = NULL;
    convertIntoDLL(root,head); 
    printLinkedList(head);
    
}
#include<bits/stdc++.h>
#include"basics.cpp"
using namespace std;

Node* constructTreeFromInorder(int arr[],int s,int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    Node* root= new Node(arr[mid]);
    root->left = constructTreeFromInorder(arr,s,mid-1);
    root->right = constructTreeFromInorder(arr,mid+1,e);
    return root;
}

// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8};
//     Node* root = constructTreeFromInorder(arr,0,7);
//     printBST(root);
//     return 0;
// }
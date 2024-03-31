#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data = data;
        right = left = NULL;
    }
};

void buildTreeFromLevel(node *&root)
{
    queue<node *> q;
    cout << "enter the data for root node: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (q.size() > 0)
    {
        node *temp = q.front();
        q.pop();
        cout << "enter data for left: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "enter data for right: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void printTreeLinear(node *root)
{
    queue<node *> q;
    q.push(root);
    // q.push(NULL);

    while (q.size() > 0)
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << "  ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void printTree(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 0)
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (q.size() > 0)
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void lastRow(node* root){
    if(root==NULL) return;
    vector<int > ans;
    queue<node *> q;
    q.push(root);
    // q.push(NULL);

    while (q.size() > 0)
    {
        node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        
    }
    reverse(ans.begin(),ans.end());
    int n = ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"  ";
    }

}

void printTreewithoutNULL(node *root)
{
    queue<node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        int size = q.size();
        while(size--){
            node *temp = q.front();
            q.pop();

            cout << temp->data << "  ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
}

int main()
{
    //           1
    //     3           5
    // 7      11            17
    //      2     4      5       6 

    node *root = NULL;
    buildTreeFromLevel(root);
    lastRow(root);
    // cout<<"\n linear tree: ";
    // printTreeLinear(root);
    // cout<<endl;
    // cout << "2D form tree: \n";
    // printTree(root);
    // printTreewithoutNULL(root);

    return 0;
}
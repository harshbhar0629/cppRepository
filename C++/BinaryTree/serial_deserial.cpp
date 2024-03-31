
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)  return "";
        queue<TreeNode *> q;
        string s("");
        q.push(root);
        while (q.size())
        {
            root = q.front();
            q.pop();
            if (root == NULL)
                s += "#,";
            else
                s += to_string(root->val) + ',';
            if (root)
            {
                q.push(root->left);
                q.push(root->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)  {
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* cur = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                cur->left = nullptr;
            }
            else{
                cur->left = new TreeNode(stoi(str));
                q.push(cur->left);
            }
            getline(s,str,',');
            if(str=="#"){
                cur->right = nullptr;
            }
            else{
                cur->right = new TreeNode(stoi(str));
                q.push(cur->right);
            }
        }
    }
};
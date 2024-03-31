/*
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such 
that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is,
if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
        1
      /   \
     2     3
    /     /  \
   4     5    6
   pair first including sum or second excluding sum
res.first = root->data + left.second + right.second;
res.second = max(left.first,left.second) + max(right.second,right.first);

*/
class solution{
public:
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        pair<int,int> res ;
        res.first = root->data + left.second + right.second;
        res.second =  max(left.first,left.second) + max(right.second,right.first);
        return res;
    }
    int nonAdjacentMaxSum(TreeNode* root){
        pair<int,int> ans= solve(root);
        return max(ans.first,ans.second);
    }
};
class Solution {
    
    int countNodes(struct Node* tree){
        if(tree == NULL) 
            return 0;
        int ans = 1+ countNodes(tree->left) + countNodes(tree->right);
        
        return ans;
    }
    
    bool isMaxOrder(struct Node* root){
        if(root->left==NULL and root->right==NULL) 
            return true;      
            
        if(root->right == NULL ){
            return root->data > root->left->data;
        }
        else{
            
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return( (left and right) and 
            (root->data > root->left->data and root->data > root->right->data));
        }
    }
    
    bool isCBT(struct Node* root,int index ,int totalNode){
        if(root==NULL)
            return true;
            
        if(index >= totalNode){
            return false;
        }
        else{
            
            bool left = isCBT(root->left,2*index+1,totalNode);
            bool right = isCBT(root->right,2*index+2,totalNode);
            
            return (left and right);
        }
        
    }
    
  public:
    bool isHeap(struct Node* tree) {
        
        int i=0;
        int totalNode = countNodes(tree);
    
        if(isCBT(tree,i,totalNode) and isMaxOrder(tree)){
            return true;
        }
        else return false;

    }
};
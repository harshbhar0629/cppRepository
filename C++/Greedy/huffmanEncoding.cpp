class node{
  public:
  int val;
  node* left;
  node* right;
      node(int data){
          this->val = data;
          left = right  =NULL;
      }
};

class cmp{
  public:
    bool operator()(node* a,node* b){
        return a->val > b->val;
    }
};

class Solution{
    
    void traversal(node* root,string temp,vector<string>& ans){
        
        if(root->left == NULL and root->right == NULL){
            ans.push_back(temp);
            return;
        }
        
        traversal(root->left,temp + '0',ans);
        traversal(root->right,temp+'1',ans);
    }
     
	public:
    
		vector<string> huffmanCodes(string s,vector<int> f,int n){
		  
		    priority_queue<node*,vector<node*> ,cmp> pq;
		    for(int i=0;i<n;i++){
		   
		        node* temp= new node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size()>1){
		     
		        node* left = pq.top();
		        pq.pop();
		        
		        node* right = pq.top();
		        pq.pop();
		        
		        node* newNode = new node(left->val+right->val);
		        newNode->left = left;
		        newNode->right = right;
		        pq.push(newNode);
		    }
		    
		    node* root = pq.top();
		    vector<string> ans;
		    string temp="";
		    traversal(root,temp,ans);
		    
		    return ans;
		}
};
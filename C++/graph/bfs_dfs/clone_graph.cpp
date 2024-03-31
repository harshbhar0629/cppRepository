// https://leetcode.com/problems/clone-graph/
#include <bits/stdc++.h>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


vector<Node*> nodeRegister;

void dfs(Node* src, Node* clone){
    
    for(auto& neighbour: src->neighbors){
        if(nodeRegister[neighbour->val] == NULL){
            Node* nn = new Node(neighbour->val);
            nodeRegister[nn->val] = nn;
            clone->neighbors.push_back(nn);
            dfs(neighbour, nn);
        }
        else{
            clone->neighbors.push_back(nodeRegister[neighbour->val]);
        }
    }

}


Node* cloneGraph(Node* src){
    if(!src) return src;
    Node* clone = new Node(src->val);
    nodeRegister.resize(105, NULL);
    nodeRegister[clone->val] = clone;

    dfs(src, clone);
    return clone;
} 



int main(){
    

    return 0;
}
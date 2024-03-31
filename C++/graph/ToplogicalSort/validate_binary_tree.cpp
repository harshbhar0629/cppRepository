#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/validate-binary-tree-nodes/

using pi = pair<int, int>;
class Solution {

    int findRoot(int n, vector<int>& left, vector<int>& right){
        unordered_set<int>st;
        st.insert(left.begin(), left.end());
        st.insert(right.begin(), right.end());

        for(int i=0; i<n; i++){
            if(st.find(i) == st.end()) return i;
        }
        return -1;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if(root==-1) return false;
        
        queue<int>q;
        unordered_set<int>st;
        q.push(root);
        st.insert(root);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child: {leftChild[node],rightChild[node]}){
                if(child!=-1){
                    if(st.find(child) != st.end()) return false;
                    q.push(child);
                    st.insert(child);
                }
            }
        }

        return st.size()==n;
    }
};


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indeg(n,0);

        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                indeg[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                indeg[rightChild[i]]++;
            }
        }

        int root = -1;

        for(int i=0; i<n; i++){
            if(indeg[i]>1) return false;
            if(indeg[i]==0){
                if(root!=-1) {
                    return false;
                }
                root = i;
            }
        }
        if(root==-1) return false;

        vector<bool>vis(n, false);
        queue<int>q;
        q.push(root);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(vis[node]) {
                return false;
            }
            vis[node] = true;

            if(leftChild[node]!=-1){
                q.push(leftChild[node]);
            }  

            if(rightChild[node]!=-1){
                q.push(rightChild[node]);
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};


int main(){
    

    return 0;
}
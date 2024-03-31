#include <bits/stdc++.h>
using namespace std;

class Trie{
public:
    Trie *child[10];
    Trie(){
        memset(child, NULL, sizeof child);
    }

    void insert(string& s, Trie* root){
        Trie *curr = root;
        for (auto& ch: s){
            int idx = ch - '0';
            if(curr->child[idx] == NULL){
                curr->child[idx] = new Trie();
            }
            curr = curr->child[idx];
        }
    }

    int commonPrefix(string& s, Trie* root){
        Trie *curr = root;
        int len = 0;
        for(auto& ch: s){
            int idx = ch - '0';
            if(curr->child[idx] == NULL){
                return len;
            }
            curr = curr->child[idx];
            len++;
        }
        return len;
    }
};

class Solution{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2){
        Trie *root = new Trie();
        for (auto num : arr1){
            string s = to_string(num);
            root->insert(s, root);
        }
        int maxLen = 0;
        for (auto num : arr2){
            string s = to_string(num);
            int len = root->commonPrefix(s, root);
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};

int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Trie{
public:
    Trie* child[26];
    int size, index;
    Trie(){
        size = 0, index = -1;
        memset(child, NULL, sizeof child);
    }

    void insert(string &s, Trie* root, int ii){
        Trie *curr = root;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--){
            int idx = s[i] - 'a';
            if(curr->child[idx] == NULL){
                curr->child[idx] = new Trie();
            }
            curr = curr->child[idx];
            if(curr->size > n || curr->size == 0 || curr->index == -1){
                curr->size = n;
                curr->index = ii;
            }
        }
    }

    int commonSuffix(Trie* root, string &s){
        Trie *curr = root;
        for (int i = s.size()-1; i>=0; i--){
            cout << s[i] << " ";
            int idx = s[i] - 'a';
            if (curr->child[idx] == NULL){
                cout << "\n";
                return curr->index;
            }
            curr = curr->child[idx];
        }
        cout << "\n";
        return curr->index;
    }

};

class Solution{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery){
        Trie *root = new Trie();
        int mini = 1e8;
        int index = 0;
        for (int i = 0; i < wordsContainer.size(); i++){
            root->insert(wordsContainer[i], root, i);
            int sz = wordsContainer[i].size();
            if(mini > sz){
                index = i;
                mini = sz;
            }
        }
        vector<int> ans;
        for(auto& query: wordsQuery){
            int idx = root->commonSuffix(root, query);
            idx = (idx == -1) ? index : idx;
            ans.push_back(idx);
        }

        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> words(n), query(n);
    for (int i = 0; i < n; i++){
        cin >> words[i];
    }
    for (int i = 0; i < n; i++){
        cin >> query[i];
    }

    Solution s;
    vector<int> ans = s.stringIndices(words, query);
    for(auto len: ans){
        cout << len;
    }

    cout << "\n";
    return 0;
}
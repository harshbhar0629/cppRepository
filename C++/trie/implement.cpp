#include <bits/stdc++.h>
using namespace std;

void file_i_o(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return;
}


class Trie{
    public:
    bool isTerminal;
    Trie* child[26];
    char ch;
    Trie(char ch){
        // child = new Trie(26);
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
        this->ch = ch;
        isTerminal = false;
    }
};


void insert_word(Trie* root, string& s, int i){
    
    if(s.size()==i){
        root->isTerminal = true;
        return;
    }
    int idx = s[i] - 'a';
    Trie* c;
    if(root->child[idx] != NULL){
        c = root->child[idx];
    }
    else{
        c = new Trie(s[i]);
        root->child[idx] = c;
    }
    insert_word(c, s, i+1);
}


bool search_word(string& s, Trie* root, int i){
    if(s.size()==i){
        return root->isTerminal;
    }
    int idx = s[i]-'a';
    if(root->child[idx] == NULL) return false;
    return search_word(s, root->child[idx], i+1);
}

void deletion(string &s, Trie* root, int i){
    if(i==s.size()){
        root->isTerminal = false;
        return;
    }
    int idx = s[i] - 'a';
    if(root->child[idx] == NULL) return;
    deletion(s, root->child[idx], i+1);
}

int main(){
    // file_i_o();

    Trie* root = new Trie('-');
    int n;
    cout<<"queries: ";
    cin>>n;
    while(n--){
        string s;
        cout<<"insert string \n";
        cin>>s;
        insert_word(root, s, 0);
        cout<<"Insertion Done \n";
        cout<<"search string: ";
        cin>>s;
        if(search_word(s, root, 0)) cout<<"Found\n";
        else cout<<"not Found \n";
        cin>>s;
        deletion(s,root, 0);
    } 


    return 0;
}
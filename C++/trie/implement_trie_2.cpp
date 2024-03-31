#include <bits/stdc++.h>
using namespace std;
// Leetcode : 1804
// https://www.codingninjas.com/studio/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM

class Node{
public:
    unordered_map<char, Node*> child;
    char data;
    bool isTerminal;
    int countWordStarting;
    int countWordEndingHere;

    Node(char data){
        this->data = data;
        this->isTerminal = false;
        this->countWordStarting = this->countWordEndingHere = 0;
    }
};

class Trie{
public:
    Node *root;
    Trie(){
        root = new Node('\0');
    }

    void insert(string word){
        Node *curr = root;
        for (int i = 0; i < word.size(); i++){
            char ch = word[i];
            //finding current character in Trie if if is found then go to its child and inc its count as well
            if(curr->child.count(ch)){
                curr = curr->child[ch];
                curr->countWordStarting++;
            }
            else{
                //if we dont't able to find character then we have to make a new character and make its entry in its parent
                //inc its count and move our curr pointer
                Node *newChild = new Node(ch);
                curr->child[ch] = newChild;
                curr = curr->child[ch];
                curr->countWordStarting++;
            }
        }

        curr->isTerminal = true;
        curr->countWordEndingHere++;
    }

    int countWordsEqualTo(string word){
        Node *curr = root;
        for (int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(curr->child.count(ch)){
                curr = curr->child[ch];
            }
            else {
                return 0;
            }
        }
        return curr->countWordEndingHere;
    }

    int countWordsStartingWith(string prefix){
        Node *curr = root;
        for (int i = 0; i < prefix.size(); i++){
            char ch = prefix[i];
            if(curr->child.count(ch)){
                curr = curr->child[ch];
            }
            else{
                return 0;
            }
        }
        return curr->countWordStarting;
    }

    void erase(string word){
        Node *curr = root;
        for (int i = 0; i < word.size(); i++){
            char ch = word[i];
            curr = curr->child[ch];
            curr->countWordStarting--;
        }
        curr->isTerminal = false;
        curr->countWordEndingHere--;
    }
};

int main(){
    Trie t;
    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        if(x==1){
            string s;
            cin >> s;
            t.insert(s);
        }
        if(x==2){
            string s;
            cin >> s;
            cout << "Ans: " << t.countWordsEqualTo(s);
        }
        if(x==3){
            string s;
            cin >> s;
            cout << "Ans: " << t.countWordsStartingWith(s);
        }
        if(x==4){
            string s;
            cin >> s;
            t.erase(s);
        }
        cout << endl;
    }

    return 0;
}

/**
 * Input                               output
 * Trie
 * 1 insert                        apple
 * 1 insert                        apple
 * 2 countWordsEqualTo             apple      2
 * 3 countWordsStartingWith        app        2
 * 4 erase                         apple
 * 2 countWordsEqualTo             apple      1
 * 3 countWordsStartingWith        app        1
 * 4 erase                         apple
 * 3 countWordsStartingWith        app        0
 */

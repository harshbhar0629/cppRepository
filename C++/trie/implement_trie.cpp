#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Node
{
public:
    char data;
    unordered_map<char, Node *> child;
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
        isTerminal = false;
    }

    void makeTerminal()
    {
        this->isTerminal = true;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (curr->child.count(ch))
            {
                curr = curr->child[ch];
            }
            else
            {
                Node *newChild = new Node(ch);
                curr->child[ch] = newChild;
                curr = newChild;
            }
        }
        curr->makeTerminal();
    }

    bool search(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (curr->child.count(ch))
            {
                curr = curr->child[ch];
            }
            else
            {
                return false;
            }
        }
        return curr->isTerminal;
    }

    bool startsWith(string prefix)
    {
        Node *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            char ch = prefix[i];
            if (curr->child.count(ch))
            {
                curr = curr->child[ch];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    

    return 0;
}
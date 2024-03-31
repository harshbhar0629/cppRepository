#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-ladder-ii/submissions/1196152792/

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList){
    vector<vector<string>> ans;
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> qu;
    qu.push({beginWord});
    st.erase(beginWord);
   
    while(!qu.empty()){
        vector<string> visited;
        int size = qu.size();

        for (int i = 0; i < size; i++){
            auto curr = qu.front();
            qu.pop();
            string word = curr.back();
            if(word == endWord){
                ans.push_back(curr);
                continue;
            }

            for (int i = 0; i < word.size(); i++){
                char orgCh = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        // insert in current list of string
                        curr.push_back(word);
                        // insert this list into our queue
                        qu.push(curr);
                        // mark as visited bcoz we have to erase this word after this level
                        visited.push_back(word);
                        // why pop bcoz we require some more words at same time if we add this word then our list having one more words
                        curr.pop_back();
                    }
                }
                word[i] = orgCh;
            }
        }
        for(auto it: visited){
            // erase all words which come in before this level
            st.erase(it);
        }
    }
    return ans;
}

class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string beginWord;

    void dfs(string &word, vector<string> &vec)
    {
        if (word == beginWord)
        {
            ans.emplace_back(vec);
            reverse(ans.back().begin(), ans.back().end());
            return;
        }
        int step = mp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char orgCh = word[i];
            for (auto ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.count(word) > 0 and mp[word] + 1 == step)
                {
                    vec.emplace_back(word);
                    dfs(word, vec);
                    vec.pop_back();
                }
            }
            word[i] = orgCh;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        this->beginWord = beginWord;
        queue<string> qu;
        qu.push(beginWord);
        st.erase(beginWord);
        mp[beginWord]++;

        while (!qu.empty())
        {
            string word = qu.front();
            int step = mp[word];
            qu.pop();

            for (int i = 0; i < word.size(); i++)
            {
                char orgCh = word[i];
                for (auto ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0)
                    {
                        qu.push(word);
                        mp[word] = step + 1;
                        st.erase(word);
                    }
                }
                word[i] = orgCh;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> vec;
            vec.emplace_back(endWord);
            dfs(endWord, vec);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
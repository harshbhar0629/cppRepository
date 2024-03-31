#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/word-ladder/1
// https://leetcode.com/problems/word-ladder/submissions/1195849997/

class Solution{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList){
        unordered_set<string> st;
        for (auto word : wordList){
            st.insert(word);
        }
        st.erase(startWord);

        queue<pair<string, int>> qu;
        qu.push({startWord, 1});

        // TC: O(M*26*N) n-> size of word list
        while (!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            string word = curr.first;
            int step = curr.second;
            if (word == targetWord){
                return step;
            }
            // TC: O(M*26) where M-> wordList[i].length()
            for (int i = 0; i < word.size(); i++){
                char orgCh = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        if (word == targetWord){
                            return step + 1;
                        }
                        st.erase(word);
                        qu.push({word, step + 1});
                    }
                }
                word[i] = orgCh;
            }
        }
        return 0;
    }
};

int main(){
    

    return 0;
}
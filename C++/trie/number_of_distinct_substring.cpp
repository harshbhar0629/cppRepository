#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?leftPanelTabValue=PROBLEM

void f(string& s, unordered_set<string>& st, string t = "", int i=0){
    if(i == s.size()){
        st.insert(t);
        return;
    }
    f(s, st, t, i + 1);
    if(t=="" || t.back() == s[i-1]){
        t += s[i];
        f(s, st, t, i + 1);
    }
}

int count_distinct_substring(string s){
    unordered_set<string> st;
    f(s, st);
    for(auto it: st){
        cout << it << " ";
    }
    cout << endl;
    return st.size();
}

/*********************************************************************************/

int countDistinctSubstrings(string &s)
{
    unordered_set<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        string t = "";
        for (int j = i; j < s.size(); j++)
        {
            t += s[j];
            st.insert(t);
        }
    }

    return st.size()+1;
}

/*****************************************************************/

class Trie
{
public:
    Trie *child[26];
    Trie()
    {
        memset(child, NULL, sizeof child);
    }
};

int countDistinctSubstrings1(string &s)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Trie *root = new Trie();
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        Trie *head = root;
        for (int j = i; j < s.size(); j++)
        {
            if (head->child[s[j] - 'a'] == NULL)
            {
                ans++;
                head->child[s[j] - 'a'] = new Trie();
            }
            head = head->child[s[j] - 'a'];
        }
    }

    return ans + 1;
}

int main(){
    string s;
    cin >> s;

    // cout << count_distinct_substring(s);
    // cout << countDistinctSubstrings(s);

    return 0;
}
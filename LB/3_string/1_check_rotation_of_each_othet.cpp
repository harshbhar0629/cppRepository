// https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include <bits/stdc++.h>
using namespace std;

class Solution{
        
    // bool isEqual(string& s, string& t, int idx){
    //     int n = s.size();
    //     for(int i=0; i<n; i++){
    //         if(s[i] != t[(i+idx)%n] ) return false;
    //     }
    //     return true;
    // }    
    
public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s,string t){
        
        queue<char>q, qu;
        int n = s.size(), m = t.size();
        if(n!=m) return false;
        
        for(int i=0; i<n; i++){
            q.push(s[i]);
        }
        for(int i=0; i<m; i++){
            qu.push(t[i]);
        }
        
        int k = n;
        
        while(k--){
            qu.push(qu.front());
            qu.pop();
            if(q==qu) return true;
        }
        return false;
        
        // int n = s1.size();
        // int m = s2.size();
        // if(n!=m) return false;
        
        // vector<int>idx;
        // char ch = s1[0];
        
        // for(int i=0; i<m; i++){
        //     if(s2[i]==ch) idx.push_back(i);
        // }
        // for(int i=0; i<idx.size(); i++){
        //     bool b = isEqual(s1, s2, idx[i]);
        //     if(b) return true;
        // }
        // return false;
    }
};

int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindrome-partitioning/description/


class solution{

    bool isPalindrome(string &s, int i, int j){
        if(i==j) return true;
        for(; i<j; i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>>ans;
    void f(int i, int n, string& s, vector<string>& temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        for(int k=i; k<n; k++){
            if(isPalindrome(s, i, k)){
                temp.push_back(s.substr(i, k-i+1));
                f(k+1, n, s, temp);
                temp.pop_back();
            }
        }
    }

public:
    
    vector<vector<string>> partition(string s) {
        if(s.size()==1) {
            return {{s}};
        }
        vector<string>temp;
        f(0, s.size(), s, temp);

        return ans;
    }
};


int main(){
    

    return 0;
}
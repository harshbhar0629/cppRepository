#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1

class Solution{

    vector<string>res;
    void f(string&s, int i, string t){
        if(i==s.size()){
            res.push_back(t);
            return ;
        }
        f(s, i+1, t+s[i]);
        if(i!=s.size()-1) f(s, i+1, t+s[i]+' ');
    }

public:

    vector<string> permutation(string s){
       f(s, 0, "");
       sort(res.begin(), res.end());
       return res;
    }
};


int main(){
   

    return 0;
}
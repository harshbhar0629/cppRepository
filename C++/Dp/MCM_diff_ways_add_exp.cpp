#include <bits/stdc++.h>
using namespace std;


class Solution {

    int solve(int x,int y,char ch){
        if(ch=='-') return x-y;
        else if(ch=='+') return x+y;
        else if(ch=='/') return x/y;
        return x*y;
    }

public:
    vector<int> diffWaysToCompute(string exp) {

        int n = exp.size();
        vector<int>ans;
        bool flag = true;
        for(int i=0; i<n; i++){
            if(!isdigit(exp[i])){
                flag = false;
                vector<int> left = diffWaysToCompute(exp.substr(0,i));
                vector<int> right = diffWaysToCompute(exp.substr(i+1));
                for(auto x: left){
                    for(auto y: right){
                        int c = solve(x,y,exp[i]);
                        ans.push_back(c);
                    }
                }
            }
        } 
        if(flag) {
            ans.push_back(stoi(exp));
        }
        return ans;
    }
};


int main(){
    

    return 0;
}
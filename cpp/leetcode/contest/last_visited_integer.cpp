// https://leetcode.com/contest/biweekly-contest-115/problems/last-visited-integers/
#include <bits/stdc++.h>
using namespace std;

vector<int> lastVisitedIntegers(vector<string>&words){
    
    int n = words.size(), count=0;
    vector<int>ans,v;

    for(int i=0; i<n; i++){
        if(words[i]=="prev"){
            count++;
            if(count>v.size()){
                ans.push_back(-1);
            }else{
                ans.push_back(v[v.size()-count]);
            }
        }else{
            count=0;
            v.push_back(stoi(words[i]));
        }
    }
    return ans;
}

int main(){
    int n;
    vector<string> words(n);
    for(int i=0; i<n; i++){
        cin>>words[i];
    }

    vector<int>ans =  lastVisitedIntegers(words);

    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}
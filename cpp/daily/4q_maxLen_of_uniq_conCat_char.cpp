// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
#include <bits/stdc++.h>
using namespace std;

bool hasDuplicate(string& s, string& t){
    int arr[26]= {0};
    for(auto it: s){
        if(arr[it-'a']>0) return true;
        arr[it-'a']++;
    }
    for(auto it: t){
        if(arr[it-'a']>0) return true;
    }
    return false;
}
int n;
int f(vector<string>& arr, int i,string temp){
    if(i>=n){
        return temp.size();
    }
    int include=0, exclude=0;
    
    if(hasDuplicate(arr[i], temp)){
        exclude = f(arr, i+1, temp);
    }
    else{
        include = f(arr, i+1, temp+arr[i]);
        exclude = f(arr, i+1, temp);
    }

    return max(include, exclude);
}

int main(){
    

    return 0;
}
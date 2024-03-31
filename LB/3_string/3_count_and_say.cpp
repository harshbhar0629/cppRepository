// https://leetcode.com/problems/count-and-say/
#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n){
    if(n==1) return "1";
    string s = countAndSay(n-1);
    string ans("");

    int count =1;
    char ch = s[0];

    for(int i=1; i<n; i++){
        if(ch==s[i]) count++;
        else{
            ans += (to_string(count) + ch);
            ch = s[i];
            count=1;
        }
    }
    ans += (to_string(count) + ch);
    return ans;
}

int main(){
    

    return 0;
}
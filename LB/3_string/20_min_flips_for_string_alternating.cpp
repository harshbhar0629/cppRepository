// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();
        s+=s;
        string t(""), str("");

        for(int i=0; i<2*n; i++){
            t += (i%2==0)?'1':'0';
            str += (i%2==0)?'0':'1';
        }
        
        int ans1=0, ans2=0, ans=INT_MAX;

        for(int i=0; i<2*n; i++){
            ans1 += (s[i]!=t[i]);
            ans2 += (s[i]!=str[i]);
            if(i>=n){
                ans1 -= (s[i-n]!=t[i-n]);
                ans2 -= (s[i-n]!=str[i-n]);
                ans = min({ans1, ans, ans2});
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}
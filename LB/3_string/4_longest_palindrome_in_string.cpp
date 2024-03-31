// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalin (string s) {
        int n= s.size();
        int len =1, start=0;
        for(int i=1; i<n; i++){
            // even substring
            int l = i-1;
            int h = i;
            while(l>=0 and h<n and s[l]==s[h]){
                if(h-l+1>len){
                    len = h-l+1;
                    start = l;
                }
                l--,h++;
            }
            // odd substring
            l = i-1;
            h=i+1;
            while(l>=0 and h<n and s[l]==s[h]){
                if(h-l+1>len){
                    len = h-l+1;
                    start = l;
                }
                l--,h++;
            }
        }
        string ans("");
        for(int i=start; i<=len+start-1; i++){
            ans+=s[i];
        }
        return ans;
    }
};


int main(){
    

    return 0;
}
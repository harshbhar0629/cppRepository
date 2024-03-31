// https://leetcode.com/problems/count-binary-substrings/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1, prev = 0, n = s.size(), ans=0;
        
        for(int i=1; i<n; i++){
            if(s[i-1]==s[i]){
                curr++;
            }
            else{
                ans+=min(prev, curr);
                prev = curr;
                curr=1;
            }
        } 
        ans+=min(prev, curr);
        return ans;
    }
};

int main(){
    

    return 0;
}
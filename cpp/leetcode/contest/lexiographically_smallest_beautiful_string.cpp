#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
      
        int minLen = 1000, n = s.size();
        vector<string>v;
        for(int i=0; i<=n-k; i++){
            int c=0;
            string curr="";
            for(int j=i; j<n; j++){
                curr+=s[j];
                if(s[j]=='1') c++;
                if(c==k) break;
            }
            if(c==k){
                v.push_back(curr);
                int len = curr.size();
                minLen = min(minLen,len);
            }
        }
        if(v.size()==0) return "";

        vector<string>ans;
        for(int i=0; i<v.size(); i++){
            if(minLen == v[i].size()) ans.push_back(v[i]);
        }
        sort(ans.begin(),ans.end());

        return ans[0];
    }
};


int main(){
    

    return 0;
}
// https://leetcode.com/problems/row-with-maximum-ones/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        vector<int>ans(2,0);

        for(int i=0; i<n; i++){
            int one = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j]==1) one++;
            }
            if(one>ans[1]){
                ans[0] = i;
                ans[1] = one;
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}
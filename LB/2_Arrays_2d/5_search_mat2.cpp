// https://leetcode.com/problems/search-a-2d-matrix-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int n = mat.size(), m = mat[0].size();
        int i=0 , j=m-1;

        while(i<n and j>=0){
            if(mat[i][j] == target) return true;
            else if(mat[i][j]<=target){
                i++;
            }
            else j--;
        }

        return false;

    }
};

int main(){
    

    return 0;
}
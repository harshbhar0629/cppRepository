// https://leetcode.com/problems/search-a-2d-matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int n = mat.size() ,m = mat[0].size();
        int low = 0 , high = m*n-1;
        // if(n==1 and m==1){
        //     return mat[0][0]==target;
        // }

        while(low<=high){
            int mid = (low+high)/2;
            int i = mid/m;
            int j = mid%m;
            if(mat[i][j]==target) return true;
            else if(mat[i][j]<=target){
                low = mid+1;
            }
            else high = mid - 1;
        }
        return false;
    }
};

int main(){
    

    return 0;
}
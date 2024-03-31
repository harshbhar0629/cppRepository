// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c){

        int reqCnt = (1 + r*c)/2;
        int lo = 1e5, hi = -1;
        for(int i=0; i<r; i++){
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][c-1]);
        }
        
        int ans =0;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int cnt =0 ;
            for(int i=0; i<r; i++){
                cnt+=upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            if(cnt>=reqCnt){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    
        // vector<int>v;
        // for(int i=0; i<r; i++){
        //     for(int j=0; j<c; j++){
        //         v.push_back(mat[i][j]);
        //     }
        // }
        
        // sort(v.begin(), v.end());
        // return v[v.size()/2];
    }
};


int main(){
    

    return 0;
}
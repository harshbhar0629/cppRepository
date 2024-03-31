// https://leetcode.com/problems/matchsticks-to-square/
#include <bits/stdc++.h>
using namespace std;


class Solution {

    vector<int>v;
    bool f(vector<int>& mat, int idx, int target){
        if(idx>=mat.size()){
            return (v[0] == v[1] and v[1] == v[2] and v[2] == v[3]);
        }
        for(int i=0; i<4; i++){
            if(v[i]+mat[idx] > target){ //optimization 1
                continue;
            }
            // optimization 3
//suppose arr = 3 4 5 7 9 5 and our matchstick is 3 and if we add 3 in 5 it gives 8 and but now we have 2..5 then they both generate calls so, we can just skip any of them  
            int j = i-1;
            while(j>=0){
                if(v[j]==v[i]) break;
                j-=1;
            }
            if(j!=-1) continue;

            v[i]+=mat[idx];
            if(f(mat, idx+1, target)) return true;
            v[i] -= mat[idx]; //just backtrack
            if(v[i]==0) break;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int maxi = matchsticks[0], sum=0;
        int n = matchsticks.size();
        for(int i=0; i<n; i++){
            sum+=matchsticks[i];
            maxi = max(maxi, matchsticks[i]);
        }

        if(sum%4 != 0) return false; //optimization 2
        int target = sum/4;

        if(target < maxi) return false; //optimization 2
        v.resize(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return f(matchsticks, 0, target);
    }
};

int main(){
    

    return 0;
}
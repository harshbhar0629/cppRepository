#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/brick-wall/description/

#define ll long long int
class Solution {
public:
    int leastBricks(vector<vector<int>>& walls) {
        int n = walls.size();
        int maxi = 0;
        unordered_map<ll,int>mp;

        for(int i=0; i<n; i++){
            ll sum = 0;
            for(int j=0; j<walls[i].size()-1; j++){
                ll bri = walls[i][j];
                sum += bri;
                mp[sum]++;
                if(mp[sum] > maxi){
                    maxi = mp[sum];
                }
            }
        }

        return walls.size() - maxi;
    }
};

int main(){
    

    return 0;
}
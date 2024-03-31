#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/grid-illumination/

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> x_cord;    // it denotes bulb position in x-direction
        unordered_map<int,int> y_cord;    // it denotes bulb position in y-direction
        unordered_map<int,int> left_dia;  // it denotes bulb in their left-diagonal eqn(x-y)
        unordered_map<int,int> right_dia; // it denotes bulb in their right-diagonal eqn(x+y)

        set<pair<int,int>>st;
        for(auto &l: lamps){
            int x = l[0];
            int y = l[1];

            if(st.find({x, y}) == st.end()){
                st.insert({x, y});
                x_cord[x]++;
                y_cord[y]++;
                right_dia[x+y]++;
                left_dia[x-y]++;
            }
        }

        // int m = queries.size();
        vector<int>ans;
        for(auto &q: queries){
            int x = q[0];
            int y = q[1];
            if(x_cord[x] > 0 || y_cord[y] > 0 || left_dia[x-y] > 0 || right_dia[x+y] > 0){
                ans.push_back(1);

                // iterate all it's 8-neighbour
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        int qx = x+ i;
                        int qy = y+ j;

                        if(st.count({qx, qy}) == 0 || x_cord[qx] == 0 || y_cord[qy] == 0 || left_dia[qx-qy] == 0 || right_dia[qx+qy] == 0){
                            continue;
                        }
                        st.erase({qx, qy});
                        x_cord[qx]--;
                        y_cord[qy]--;
                        right_dia[qx+qy]--;
                        left_dia[qx-qy]--;
                    }
                }
            }else{
                ans.push_back(0);
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
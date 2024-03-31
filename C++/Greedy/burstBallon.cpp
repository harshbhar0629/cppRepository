#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    static bool cmp(vector<int> &a,vector<int>& b){
        return a[1]<b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);
        int n = points.size();
        int lastEndTime = points[0][1];
        int ansCount=0;
       
        for(int i=1;i<n;i++){
            if(points[i][0] <= lastEndTime){
                ansCount++;
            }
            else{
                lastEndTime = points[i][1];
            }
            
        }

        return n- ansCount;
    }
};

int main()
{

    return 0;
}
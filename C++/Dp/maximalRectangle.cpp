// https://leetcode.com/problems/maximal-rectangle/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector<int> prev(n,-1),next(n,n);  
        stack<int>st;
        st.emplace(0);

        for(int i=1;i<n;i++){
            while(st.size()>0 and heights[st.top()] > heights[i]){
                next[st.top()] = i;
                st.pop();
            }
            if(st.size()!=0) prev[i] = st.top();
            st.emplace(i);
        }

        int maxArea = 0;
        
        for(int i=0;i<n;i++){
            int area = heights[i]*(next[i]- prev[i] -1);
            maxArea = max(area,maxArea);
        }
        
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = -1;
        vector<int>v(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == '1') v[j] += 1;
                else v[j] = 0;
            }
            maxArea = max(maxArea,largestRectangleArea(v));
        }      
        return maxArea;
    }
};


int main(){
    

    return 0;
}
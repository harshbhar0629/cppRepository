#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(), area = 0;
        stack<int> stk;

        for (int i = 0; i < n + 1; i++)
        {
            while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i]))
            {
                int height = heights[stk.top()], width = 0;
                stk.pop();
                if (stk.empty())
                    width = i;
                else
                    width = i - stk.top() - 1;
                area = max(area, width * height);
            }
            stk.push(i);
        }

        return area;
        // int n = heights.size();
        // stack<int>st;
        // vector<int>prev(n, -1), next(n, n);
        // st.push(0);

        // for(int i=1; i<n; i++){
        //     while(!st.empty() and heights[st.top()] > heights[i]){
        //         next[st.top()] = i;
        //         st.pop();
        //     }
        //     if(st.size() > 0){
        //         prev[i] = st.top();
        //     }
        //     st.push(i);
        // }

        // int maxArea = 0;
        // for(int i=0; i<n; i++){
        //     maxArea = max(maxArea, (next[i] - prev[i] -1)*heights[i]);
        // }

        // return maxArea;
    }
};

int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximal-rectangle/description/

class Solution
{

    int max_area_rectangle(vector<int> &h)
    {
        int n = h.size();
        stack<int> st;
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        st.push(0);

        for (int i = 1; i < n; i++)
        {
            while (st.size() > 0 and h[st.top()] > h[i])
            {
                next[st.top()] = i;
                st.pop();
            }
            if (st.size() != 0)
                prev[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int area = h[i] * (next[i] - prev[i] - 1);
            maxArea = max(area, maxArea);
        }
        cout << maxArea;
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int maxArea = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            int area = max_area_rectangle(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

int main(){
    

    return 0;
}
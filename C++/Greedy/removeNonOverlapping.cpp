// https://leetcode.com/problems/non-overlapping-intervals/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public: // sort by starting time
    int eraseOverlapIntervals1(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ansCount = 0;
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (lastEndTime > intervals[i][0])
            {
                ansCount++;
                lastEndTime = min(lastEndTime, intervals[i][1]);
            }
            else
            {
                lastEndTime = intervals[i][1];
            }
        }
        return ansCount;
    }

    // sort by ending time
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals2(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int ansCount = 0;
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (lastEndTime > intervals[i][0])
            {
                ansCount++;
            }
            else
            {
                lastEndTime = intervals[i][1];
            }
        }
        return ansCount;
    }
};

int main()
{
}
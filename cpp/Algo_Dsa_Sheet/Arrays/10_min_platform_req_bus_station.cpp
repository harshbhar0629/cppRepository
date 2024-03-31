#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dept[], int n)
    {
        int maxPlatform = 0;
        for (int i = 0; i < n; i++)
        {
            int platform_needed = 1;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (arr[j] <= arr[i] and dept[j] >= arr[i])
                    {
                        platform_needed++;
                    }
                }
            }
            // cout<<platform_needed<<"\n";
            maxPlatform = max(maxPlatform, platform_needed);
        }

        return maxPlatform;
    }

    int findPlatform(int arr[], int dept[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.emplace_back(arr[i], dept[i]);
        }

        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int platform_needed = 1;
        pq.push(v[0].second);
        for (int i = 1; i < n; i++)
        {
            if (pq.top() >= v[i].first)
            {
                platform_needed++;
            }
            else
            {
                pq.pop();
            }
            pq.push(v[i].second);
        }
        return platform_needed;
    }
};

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dept[], int n)
    {
        sort(arr, arr + n);
        sort(dept, dept + n);
        int i = 1, j = 0;
        int platform = 1, maxPlatform = 0;

        while (i < n and j < n)
        {
            if (arr[i] <= dept[j])
            {
                i++;
                platform++;
            }
            else
            {
                platform--;
                j++;
            }
            maxPlatform = max(maxPlatform, platform);
        }

        return max(1, maxPlatform);
    }

    int findPlatform(int arr[], int dept[], int n)
    {
        int maxDept = 0;
        for (int i = 0; i < n; i++)
        {
            maxDept = max(maxDept, dept[i]);
        }
        vector<int> v(maxDept + 2, 0);
        for (int i = 0; i < n; i++)
        {
            v[arr[i]]++;
            v[dept[i] + 1]--;
        }

        int cntPlatform = 0;
        for (int i = 1; i <= maxDept; i++)
        {
            v[i] += v[i - 1];
            cntPlatform = max(cntPlatform, v[i]);
        }

        return cntPlatform;
    }
};

int main(){
    

    return 0;
}
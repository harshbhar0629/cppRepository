#include<bits/stdc++.h>
using namespace std;
#define pp pair<double,pair<int,int>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<pp> pq;
        int n = arr.size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1 ;j<n ; j++){
                double fraction = (1.0*arr[i]) / arr[j];
                if(pq.size()<k){
                    pq.push( {fraction , {arr[i],arr[j]} } );
                }
                else{
                    if(fraction < pq.top().first){
                        pq.pop();
                        pq.push( {fraction , {arr[i],arr[j]} } );
                    }
                }
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};

class Solution
{
    static bool cmp(pair<double, pair<int, int>> &p1, pair<double, pair<int, int>> &p2)
    {
        return p1.first < p2.first;
    }

public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        vector<pair<double, pair<int, int>>> v;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int a = arr[i];
                int b = arr[j];
                v.push_back({(1.0 * a / b * 1.0), {i, j}});
            }
        }

        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].first << " ";
        }
        vector<int> ans(2);
        ans[0] = arr[v[k - 1].second.first];
        ans[1] = arr[v[k - 1].second.second];
        return ans;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<pp,vector<pp> , greater<pp>> pq;
        int n = arr.size();

        for(int i=0; i<n; i++){
            double fraction = (1.0* arr[i])/arr[n-1];
            pq.push({fraction,{i,n-1}});
        }

        while(--k){
            auto p1 = pq.top();
            pq.pop();
            int firstIdx = p1.second.first;
            int lastIdx = p1.second.second;
            if(lastIdx-1 > firstIdx){
                double fraction = (1.0* arr[firstIdx])/arr[lastIdx-1];
                pq.push({fraction,{firstIdx,lastIdx-1}});
            }
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};
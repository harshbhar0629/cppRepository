#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/find-k-closest-elements/

#define pi pair<int,int>
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        if (k == arr.size())
        {
            return arr;
        }
        int lo = 0, hi = arr.size() - 1;
        while (hi - lo >= k)
        {
            if (x - arr[lo] > arr[hi] - x)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }

        return vector<int>(arr.begin() + lo, arr.begin() + hi + 1);

        int n = arr.size();
        priority_queue<pi>pq;
        for(int i=0; i<n; i++){
            int dis = abs(arr[i] - x);
            if(pq.size() < k){
                pq.push({dis, arr[i]});
            }
            else if(pq.top().first > dis){
                pq.pop();
                pq.push({dis, arr[i]});
            }
        }
        vector<int>ans(k);
        while(k-- and !pq.empty()){
            ans[k] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    

    return 0;
}
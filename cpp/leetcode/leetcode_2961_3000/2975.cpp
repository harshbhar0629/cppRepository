#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/

#define ll long long int
class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &h, vector<int> &v)
    {

        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        unordered_set<int> st;
        // sort(h.begin(), h.end());
        // sort(v.begin(), v.end());

        for (int i = 0; i < h.size(); i++)
        {
            for (int j = i + 1; j < h.size(); j++)
            {
                int d = abs(h[j] - h[i]);
                st.insert(d);
            }
        }

        ll ans = -1;

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                int d = abs(v[j] - v[i]);
                if (st.find(d) != st.end())
                {
                    ll dis = d;
                    ans = max(ans, dis * dis);
                }
            }
        }
        int N = 1e9 + 7;
        return ans % N;
    }
};

int main(){
    

    return 0;
}
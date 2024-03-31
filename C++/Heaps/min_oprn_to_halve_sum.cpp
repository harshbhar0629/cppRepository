#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        int n = nums.size();
        int oprn = 0;
        priority_queue<double, vector<double>, less<double>> pq(nums.begin(), nums.end());
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double halve = sum / 2.0;

        while (sum > halve)
        {
            double val = pq.top() / 2.0;
            sum -= val;
            pq.pop();
            pq.push(val);
            oprn++;
        }
        return oprn;
    }
};

int main(){
    

    return 0;
}
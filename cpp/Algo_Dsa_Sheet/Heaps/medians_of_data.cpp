#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder
{
    priority_queue<int> maxHp;
    priority_queue<int, vector<int>, greater<int>> minHp;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHp.size() == 0 || maxHp.top() >= num)
        {
            maxHp.push(num);
            if (maxHp.size() > minHp.size() + 1)
            {
                minHp.push(maxHp.top());
                maxHp.pop();
            }
        }
        else
        {
            minHp.push(num);
            if (maxHp.size() < minHp.size())
            {
                maxHp.push(minHp.top());
                minHp.pop();
            }
        }
    }

    double findMedian()
    {
        if (minHp.size() == maxHp.size())
        {
            return (double)(minHp.top() * 1.0 + maxHp.top() * 1.0) / 2.0;
        }
        return maxHp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    

    return 0;
}
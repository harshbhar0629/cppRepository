#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/boats-to-save-people/

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n - 1;
        int boat = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++, j--;
                boat++;
            }
            else
            {
                j--;
                boat++;
            }
        }

        return boat;
    }
};

int main(){
    

    return 0;
}
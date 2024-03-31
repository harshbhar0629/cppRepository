#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet
{
    unordered_map<int, int> mp;
    vector<int> v;

public:
    RandomizedSet()
    {
        v = {};
    }

    bool insert(int val)
    {
        if (mp.count(val) > 0)
        {
            return false;
        }
        // cout<<"Insert\n";
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mp.count(val) == 0 || v.size() == 0)
        {
            // cout<<"remove\n";
            return false;
        }

        // get idx for deletion
        int idx = mp[val];
        // store last val of array
        int lastVal = v.back();
        // put last value in place of delete index
        v[idx] = lastVal;
        // remove last val bcoz it is updated on index val
        v.pop_back();
        // also update their map
        mp[v[idx]] = idx;
        // erase value from map also
        mp.erase(val);
        return true;
    }

    int getRandom()
    {
        // int idx = random() % v.size();
        // return v[idx];
        return 1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
*/

// https : // leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

class RandomizedCollection{
    unordered_map<int, vector<int>> mp;
    vector<pair<int, int>> v;

public:
    RandomizedCollection()
    {
        v = {};
    }

    bool insert(int val)
    {
        bool result = (mp.find(val) == mp.end());

        // insert in vector
        v.emplace_back(val, mp[val].size());
        // insert in map
        mp[val].emplace_back(v.size() - 1);

        return result;
    }

    bool remove(int val)
    {
        bool result = (mp.find(val) != mp.end());

        if (result)
        {
            int idx = mp[val].back();
            auto last = v.back();
            mp[last.first][last.second] = idx;
            v[idx] = last;
            v.pop_back();
            mp[val].pop_back();
            if (mp[val].size() == 0)
            {
                mp.erase(val);
            }
        }

        return result;
    }

    int getRandom()
    {
        return 1;
        // return v[random() % v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    

    return 0;
}
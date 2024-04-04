#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lru-cache/description/

class LRUCache
{
    int capacity = 0;
    int size = 0;
    // {key, value}
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> address;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (address.find(key) == address.end())
        {
            return -1;
        }
        auto it = address[key];
        int value = it->second;
        dll.erase(it);
        address.erase(key);
        // again insertion because we have to update key for recently used
        dll.push_front({key, value});
        address[key] = dll.begin();

        return value;
    }

    void put(int key, int value)
    {
        if (address.find(key) != address.end())
        {
            size--;
            dll.erase(address[key]);
            address.erase(key);
        }
        if (size >= capacity)
        {
            auto last = dll.back();
            dll.pop_back();
            address.erase(last.first);
            size--;
        }
        dll.push_front({key, value});
        address[key] = dll.begin();
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    

    return 0;
}
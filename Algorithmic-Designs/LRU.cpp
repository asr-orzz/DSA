#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:

    int cap = 0;

    // front = most recently used
    // back  = least recently used
    list<int> order;

    // key -> {value, position in list}
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    LRUCache(int capacity)
    {
        cap = capacity;
    }

    void touch(int key)
    {
        auto it = cache.find(key);

        // Remove key from its current position
        order.erase(it->second.second);

        // Put key at front
        order.push_front(key);

        // Update iterator
        it->second.second = order.begin();
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }

        int val = cache[key].first;

        // Make it most recently used
        touch(key);

        return val;
    }

    void put(int key, int value)
    {
        // Key already exists
        if (cache.find(key) != cache.end())
        {
            cache[key].first = value;
            touch(key);
            return;
        }

        // Cache is full
        if (cache.size() == cap)
        {
            // Remove least recently used key
            int lru = order.back();

            order.pop_back();
            cache.erase(lru);
        }

        // Insert new key at front
        order.push_front(key);

        cache[key] = {value, order.begin()};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q, cap;
    cin >> q >> cap;

    LRUCache *obj = new LRUCache(cap);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;

        if (op == "get")
        {
            int key;
            cin >> key;

            cout << obj->get(key) << '\n';
        }
        else
        {
            int key, val;
            cin >> key >> val;

            obj->put(key, val);
        }
    }

    return 0;
}
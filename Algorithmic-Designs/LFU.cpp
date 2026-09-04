#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:

    int siz = 0;
    int min_freq;
    int capacity;

    unordered_map<int, pair<int, int>> cache;
    // key -> {value, frequency}

    unordered_map<int, list<int>::iterator> freqIter;
    // key -> iterator in frequency list

    unordered_map<int, list<int>> freq;
    // frequency -> list of keys


    LFUCache(int n) {
        capacity = n;
    }


    void touch(int key) {

        int f = cache[key].second;

        // remove from old frequency list
        freq[f].erase(freqIter[key]);

        // increase frequency
        cache[key].second++;

        // add to new frequency list
        freq[f + 1].push_back(key);

        // update iterator
        freqIter[key] = --freq[f + 1].end();

        // update minimum frequency
        if (freq[min_freq].size() == 0) {
            min_freq++;
        }
    }


    int get(int key) {

        if (cache.find(key) == cache.end()) {
            return -1;
        }

        touch(key);

        return cache[key].first;
    }


    void put(int key, int value) {

        // key already exists
        if (cache.find(key) != cache.end()) {

            cache[key].first = value;

            touch(key);

            return;
        }


        // cache is full
        if (siz == capacity) {

            int key_del = freq[min_freq].front();

            cache.erase(key_del);

            freqIter.erase(key_del);

            freq[min_freq].pop_front();

            siz--;
        }


        // insert new key
        cache[key] = {value, 1};

        freq[1].push_back(key);

        freqIter[key] = --freq[1].end();

        min_freq = 1;

        siz++;
    }

};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    LFUCache* obj = new LFUCache(n);

    while (q--) {

        string op;
        cin >> op;

        if (op == "get") {

            int key;
            cin >> key;

            cout << obj->get(key) << "\n";
        }

        else if (op == "put") {

            int key, value;
            cin >> key >> value;

            obj->put(key, value);
        }
    }

    return 0;
}
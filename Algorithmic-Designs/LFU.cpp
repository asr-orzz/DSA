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


    int get(int key) {

        if (cache.find(key) == cache.end()) {
            return -1;
        }

        int val = cache[key].first;
        int f = cache[key].second;

        // remove from old frequency list
        freq[f].erase(freqIter[key]);

        // increase frequency
        cache[key].second++;

        f++;

        // add to new frequency list
        freq[f].push_back(key);

        // update iterator
        freqIter[key] = --freq[f].end();

        // if old minimum frequency became empty
        if (freq[min_freq].size() == 0) {
            min_freq++;
        }

        return val;
    }


    void put(int key, int value) {

        // key already exists
        if (cache.find(key) != cache.end()) {

            int f = cache[key].second;

            // remove from old frequency list
            freq[f].erase(freqIter[key]);

            // increase frequency
            cache[key].second++;

            f++;

            // add to new frequency list
            freq[f].push_back(key);

            // update iterator
            freqIter[key] = --freq[f].end();

            // if minimum frequency list became empty
            if (freq[min_freq].size() == 0) {
                min_freq++;
            }

            // update value
            cache[key].first = value;
        }

        else {

            // cache is full
            if (siz == capacity) {

                // least frequently used key
                int key_del = freq[min_freq].front();

                // remove from cache
                cache.erase(key_del);

                // remove its iterator
                freqIter.erase(key_del);

                // remove from frequency list
                freq[min_freq].pop_front();

                siz--;
            }

            // insert new key
            cache[key] = {value, 1};

            freq[1].push_back(key);

            freqIter[key] = --freq[1].end();

            // new key always has frequency 1
            min_freq = 1;

            siz++;
        }
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
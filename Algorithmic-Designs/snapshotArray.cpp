#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:

    vector<vector<pair<int, int>>> snapshots;
    int snapId = 0;

    SnapshotArray(int length) {

        snapshots.resize(length);

        for (int i = 0; i < length; i++) {
            snapshots[i].push_back({0, 0});
        }
    }


    void set(int index, int val) {

        if (snapshots[index].back().first == snapId) {
            snapshots[index].back().second = val;
        }
        else {
            snapshots[index].push_back({snapId, val});
        }
    }


    int snap() {
        return snapId++;
    }


    int get(int index, int snap_id) {

        auto &v = snapshots[index];

        auto it = upper_bound(v.begin(), v.end(), 
                              make_pair(snap_id, INT_MAX));

        it--;

        return it->second;
    }
};
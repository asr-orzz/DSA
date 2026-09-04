#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:

    int cap;
    vector<pair<int, int>> st;
    // {value, increment}


    CustomStack(int maxSize) {
        cap = maxSize;
    }


    void push(int x) {

        if (st.size() == cap) {
            return;
        }

        st.push_back({x, 0});
    }


    int pop() {

        if (st.empty()) {
            return -1;
        }

        int val = st.back().first;
        int inc = st.back().second;

        // pass increment to element below
        st.pop_back();

        if (!st.empty()) {
            st.back().second += inc;
        }

        return val + inc;
    }


    void increment(int k, int val) {

        if (st.empty()) {
            return;
        }

        // bottom k elements
        int idx = min(k, (int)st.size()) - 1;

        st[idx].second += val;
    }
};
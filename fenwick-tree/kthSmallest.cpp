#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    int n;
    vector<int> bit;

public:

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int x, int value) {

        while (x <= n) {
            bit[x] += value;
            x += x & -x;
        }
    }

    int query(int x) {

        int ans = 0;

        while (x > 0) {
            ans += bit[x];
            x -= x & -x;
        }

        return ans;
    }

    // Returns the smallest index x
    // such that prefix_sum(x) >= k
    int kth(int k) {

        int pos = 0;

        int currSum = 0;

        // Largest power of 2 <= n
        int power = 1;

        while (power * 2 <= n) {
            power *= 2;
        }

        for (int jump = power; jump > 0; jump >>= 1) {

            int next = pos + jump;

            if (next <= n &&
                currSum + bit[next] < k) {

                pos = next;
                currSum += bit[next];
            }
        }

        return pos + 1;
    }
};
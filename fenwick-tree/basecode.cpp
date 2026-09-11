#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    int n;
    vector<long long> bit;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Add val at index idx
    void update(int idx, long long val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

    // Sum from 1 to idx
    long long query(int idx) {
        long long sum = 0;

        while (idx > 0) {
            sum += bit[idx];
            idx -= (idx & -idx);
        }

        return sum;
    }

    // Sum from l to r
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    FenwickTree ft(10);

    ft.update(1, 5);
    ft.update(3, 7);
    ft.update(5, 2);

    cout << ft.query(5) << endl;       // 14
    cout << ft.rangeQuery(3, 5) << endl; // 9
}
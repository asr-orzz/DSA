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

    // Add value to position x
    void update(int x, int value) {
        while (x <= n) {
            bit[x] += value;
            x += x & -x;
        }
    }

    // Returns sum from 1 to x
    int query(int x) {
        int ans = 0;

        while (x > 0) {
            ans += bit[x];
            x -= x & -x;
        }

        return ans;
    }
};

int main() {
    vector<int> a = {5, 2, 5, 3, 7};

    int MAX_VALUE = 10;

    Fenwick ft(MAX_VALUE);

    // Insert elements
    for (int x : a) {
        ft.update(x, 1);
    }

    // Number of elements <= 5
    cout << ft.query(5) << '\n';

    // Number of elements > 5
    int total = a.size();

    cout << total - ft.query(5) << '\n';

    // Number of elements in [3, 6]
    cout << ft.query(6) - ft.query(2) << '\n';
}
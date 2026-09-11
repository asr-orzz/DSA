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
};

long long inversionCount(vector<int>& a) {

    int n = a.size();

    Fenwick ft(n);

    long long ans = 0;

    // Right to left
    for (int i = n - 1; i >= 0; i--) {

        // Number of elements < a[i]
        ans += ft.query(a[i] - 1);

        // Add current element
        ft.update(a[i], 1);
    }

    return ans;
}

int main() {

    vector<int> a = {5, 3, 4, 1, 2};

    cout << inversionCount(a) << '\n';
}
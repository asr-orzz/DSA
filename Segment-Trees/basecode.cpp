#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// ------------------------------------------------------------
// Segment Tree — point update + range sum
//
// Node id covers [l, r] of the array (0-based).
// Children: 2*id → [l, mid],  2*id+1 → [mid+1, r]
//
// Identity for sum (disjoint / empty range): 0
//
// Time:  Build O(n)   Update O(log n)   Query O(log n)
// Space: O(n)  (tree array size 4n)
//
// Typical use: array with point updates and range sums
//              (swap merge + identity for min / max / XOR / gcd)
// ------------------------------------------------------------

int n, q;
vector<int> a;
vector<ll> t;

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    t[id] = t[2 * id] + t[2 * id + 1]; // merge logic
}

void update(int id, int l, int r, int x, int v) {
    if (x < l or x > r) return;
    if (l == r) {
        t[id] = v;
        a[l] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * id, l, mid, x, v);
    update(2 * id + 1, mid + 1, r, x, v);

    t[id] = t[2 * id] + t[2 * id + 1]; // merge logic
}

ll query(int id, int l, int r, int lq, int rq) {
    if (rq < l or lq > r) return 0;
    if (lq <= l and r <= rq) return t[id];

    int mid = (l + r) / 2;

    return query(2 * id, l, mid, lq, rq) + query(2 * id + 1, mid + 1, r, lq, rq); // merge logic
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    a.resize(n);
    t.resize(4 * n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, v;
            cin >> x >> v;

            x--;
            update(1, 0, n - 1, x, v);
        } else {
            int l, r;
            cin >> l >> r;

            l--;
            r--;
            cout << query(1, 0, n - 1, l, r) << "\n";
        }
    }

    return 0;
}

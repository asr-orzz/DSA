#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// ------------------------------------------------------------
// Segment Tree — custom node (even / odd counts)
//
// Same skeleton as basecode.cpp. Only the node + merge change.
// Leaf stores (is_even, is_odd); merge adds counts.
// Identity for disjoint / empty range: node(0, 0)
//
// Pattern: define what a node stores → how two nodes merge →
//          leaf value on build / update. Query returns a node.
// Same idea for min+max, gcd+cnt, first/last, max subarray, …
//
// Time:  Build O(n)   Update O(log n)   Query O(log n)
// Space: O(n)  (tree array size 4n)
//
// Queries:
//   0 x y  → a[x] = y          (1-based x)
//   1 l r  → even count in [l, r]
//   2 l r  → odd  count in [l, r]
// ------------------------------------------------------------

struct node {
    int even;
    int odd;
    node(int e = 0, int o = 0) {
        even = e;
        odd = o;
    }
};

node merge(node a, node b) {
    return node(a.even + b.even, a.odd + b.odd);
}

int n, q;
vector<int> a;
vector<node> t;

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = node((a[l] % 2 == 0), a[l] % 2);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    t[id] = merge(t[2 * id], t[2 * id + 1]); // merge logic
}

void update(int id, int l, int r, int x, int v) {
    if (x < l or x > r) return;
    if (l == r) {
        t[id] = node((v % 2 == 0), v % 2);
        a[l] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * id, l, mid, x, v);
    update(2 * id + 1, mid + 1, r, x, v);

    t[id] = merge(t[2 * id], t[2 * id + 1]); // merge logic
}

node query(int id, int l, int r, int lq, int rq) {
    if (rq < l or lq > r) return node();
    if (lq <= l and r <= rq) return t[id];

    int mid = (l + r) / 2;

    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq)); // merge logic
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n);
    t.resize(4 * n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 0) {
            int x, y;
            cin >> x >> y;
            x--;
            update(1, 0, n - 1, x, y);
        } else if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(1, 0, n - 1, l, r).even << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(1, 0, n - 1, l, r).odd << "\n";
        }
    }

    return 0;
}


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, q;
vector<ll> a, t;

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    t[id] = t[2 * id] + t[2 * id + 1];
}

void update(int id, int l, int r, int x, ll v) {
    if (x < l or x > r) return;

    if (l == r) {
        t[id] += v;  // IMPORTANT: add, not assign
        return;
    }

    int mid = (l + r) / 2;
    update(2 * id, l, mid, x, v);
    update(2 * id + 1, mid + 1, r, x, v);

    t[id] = t[2 * id] + t[2 * id + 1];
}

ll query(int id, int l, int r, int lq, int rq) {
    if (rq < l or lq > r) return 0;
    if (lq <= l and r <= rq) return t[id];

    int mid = (l + r) / 2;

    return query(2 * id, l, mid, lq, rq)
         + query(2 * id + 1, mid + 1, r, lq, rq);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    a.resize(n);
    t.resize(4 * n + 1);

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Build difference array
    a[0] = arr[0];
    for (int i = 1; i < n; i++) {
        a[i] = arr[i] - arr[i-1];
    }

    build(1, 0, n-1);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            ll v;
            cin >> l >> r >> v;

            l--;
            r--;

            update(1, 0, n-1, l, v);

            if (r + 1 < n)
                update(1, 0, n-1, r+1, -v);
        }
        else {
            int i;
            cin >> i;
            i--;

            cout << query(1, 0, n-1, 0, i) << "\n";
        }
    }

    return 0;
}

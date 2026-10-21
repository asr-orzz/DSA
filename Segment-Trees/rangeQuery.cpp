#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, q;
vector<ll> a, t;

// Range Update: Add v to [lq, rq]
void update(int id, int l, int r, int lq, int rq, ll v) {

    if(r < lq || l > rq) return;

    if(lq <= l && r <= rq) {
        t[id] += v;
        return;
    }

    int mid = (l+r)/2;

    update(2*id, l, mid, lq, rq, v);
    update(2*id+1, mid+1, r, lq, rq, v);
}

// Point Query: Find arr[x]
ll query(int id, int l, int r, int x) {

    if(l == r) {
        return a[x] + t[id];
    }

    int mid = (l+r)/2;

    if(x <= mid)
        return t[id] + query(2*id, l, mid, x);
    else
        return t[id] + query(2*id+1, mid+1, r, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    a.resize(n);
    t.assign(4*n, 0);

    for(int i=0;i<n;i++) cin >> a[i];

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int l, r;
            ll v;
            cin >> l >> r >> v;

            update(1, 0, n-1, l, r, v);
        }
        else {
            int i;
            cin >> i;

            cout << query(1, 0, n-1, i) << "\n";
        }
    }
}
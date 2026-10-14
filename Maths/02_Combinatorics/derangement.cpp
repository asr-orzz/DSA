#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Time: O(n)   Space: O(1)
// Count permutations of n objects with no fixed point (derangements D_n).
//
// Recurrence: D_n = (n - 1) * (D_{n-1} + D_{n-2})
//
// Fix person 1. They cannot stay at position 1, so they have (n - 1) choices
// for where to go (say position x).
//
// Case 1 — person x goes to position 1:
//   1 and x form a swapped pair; the other n - 2 people must be deranged → D_{n-2}.
//
// Case 2 — person x does NOT go to position 1:
//   Relabel so the remaining structure is a derangement of n - 1 elements → D_{n-1}.
//
// Base: D_0 = 1 (empty permutation), D_1 = 0.
ll derangement(int n, ll mod) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }

    ll d0 = 1; // D_0
    ll d1 = 0; // D_1

    for (ll i = 2; i <= n; i++) {
        ll cur = ((i - 1) * ((d1 + d0) % mod)) % mod;
        d0 = d1;
        d1 = cur;
    }

    return d1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll mod = 1e9 + 7;
    int n;
    cin >> n;

    cout << derangement(n, mod) << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll BASE = 31;


// ============================================================
// String Hash Class
// ============================================================

class StringHash {

private:

    string s;

    vector<ll> prefixHash;
    vector<ll> power;


public:

    // --------------------------------------------------------
    // Constructor
    // --------------------------------------------------------

    StringHash(string str) {

        s = str;

        int n = s.size();

        prefixHash.resize(n + 1, 0);
        power.resize(n + 1, 0);

        power[0] = 1;

        for (int i = 0; i < n; i++) {

            // Convert character to number
            ll value = s[i] - 'a' + 1;

            prefixHash[i + 1] =
                (prefixHash[i] * BASE + value) % MOD;

            power[i + 1] =
                (power[i] * BASE) % MOD;
        }
    }


    // --------------------------------------------------------
    // Get hash of substring [l, r]
    // --------------------------------------------------------

    ll getHash(int l, int r) {

        ll result =
            prefixHash[r + 1]
            - (prefixHash[l] * power[r - l + 1]) % MOD;

        result += MOD;

        result %= MOD;

        return result;
    }


    // --------------------------------------------------------
    // Check if s[l1...r1] == s[l2...r2]
    // --------------------------------------------------------

    bool equalSubstring(int l1,
                        int r1,
                        int l2,
                        int r2) {

        if (r1 - l1 != r2 - l2) {
            return false;
        }

        return getHash(l1, r1)
             == getHash(l2, r2);
    }
};


// ============================================================
// Main
// ============================================================

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    StringHash H(s);

    int q;

    cin >> q;

    while (q--) {

        int l1, r1;
        int l2, r2;

        cin >> l1 >> r1;
        cin >> l2 >> r2;

        if (H.equalSubstring(l1, r1,
                             l2, r2)) {

            cout << "YES\n";
        }
        else {

            cout << "NO\n";
        }
    }

    return 0;
}
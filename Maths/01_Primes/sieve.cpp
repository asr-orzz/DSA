#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Time: O(n log log n)   Space: O(n)
// Returns all primes in [2, n]
vector<int> sieve(int n) {

    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {

            // remove multiples of i
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> primes = sieve(n);

    for (int p : primes) {
        cout << p << ' ';
    }
    cout << '\n';

    return 0;
}

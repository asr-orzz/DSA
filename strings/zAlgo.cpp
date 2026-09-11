#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// ------------------------------------------------------------
// Z Algorithm
//
// z[i] = length of longest substring starting from i
//        which is also a prefix of the entire string
// ------------------------------------------------------------
vector<int> computeZ(string &s) {

    int n = s.size();

    vector<int> z(n, 0);

    int l = 0;
    int r = 0;

    for (int i = 1; i < n; i++) {

        // If i lies inside current Z-box
        if (i <= r) {

            z[i] = min(r - i + 1,
                       z[i - l]);
        }

        // Try extending the match
        while (i + z[i] < n &&
               s[z[i]] == s[i + z[i]]) {

            z[i]++;
        }

        // Update Z-box
        if (i + z[i] - 1 > r) {

            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}


// ------------------------------------------------------------
// Pattern Matching using Z Algorithm
// ------------------------------------------------------------
vector<int> ZSearch(string &text, string &pattern) {

    // '#' should not occur in either string
    string s = pattern + "#" + text;

    vector<int> z = computeZ(s);

    vector<int> ans;

    int m = pattern.size();

    for (int i = m + 1; i < s.size(); i++) {

        if (z[i] == m) {

            // Convert position in combined string
            // to position in original text
            int index = i - m - 1;

            ans.push_back(index);
        }
    }

    return ans;
}


// ------------------------------------------------------------
// Main
// ------------------------------------------------------------
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;

    cin >> text;
    cin >> pattern;

    // Show Z array
    string combined = pattern + "#" + text;

    vector<int> z = computeZ(combined);

    cout << "Combined String: "
         << combined << "\n";

    cout << "Z Array: ";

    for (int x : z) {
        cout << x << " ";
    }

    cout << "\n";

    // Pattern matching
    vector<int> ans = ZSearch(text, pattern);

    cout << "Pattern occurs at indices: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
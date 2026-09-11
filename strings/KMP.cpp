#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ------------------------------------------------------------
// Compute LPS array
// lps[i] = length of longest proper prefix of pattern[0..i]
//          which is also a suffix
// ------------------------------------------------------------
vector<int> computeLPS(string &pattern) {

    int n = pattern.size();

    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {

        if (pattern[i] == pattern[len]) {

            len++;
            lps[i] = len;
            i++;
        }
        else {

            if (len != 0) {

                // Do NOT increment i
                len = lps[len - 1];
            }
            else {

                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}


// ------------------------------------------------------------
// KMP Pattern Matching
// Returns all positions where pattern occurs in text
// ------------------------------------------------------------
vector<int> KMP(string &text, string &pattern) {

    vector<int> lps = computeLPS(pattern);

    vector<int> ans;

    int n = text.size();
    int m = pattern.size();

    int i = 0;  // pointer in text
    int j = 0;  // pointer in pattern

    while (i < n) {

        if (text[i] == pattern[j]) {

            i++;
            j++;
        }

        if (j == m) {

            // Pattern found
            ans.push_back(i - j);

            // Look for next occurrence
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {

            if (j != 0) {

                j = lps[j - 1];
            }
            else {

                i++;
            }
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

    vector<int> lps = computeLPS(pattern);

    cout << "LPS Array: ";

    for (int x : lps) {
        cout << x << " ";
    }

    cout << "\n";

    vector<int> ans = KMP(text, pattern);

    cout << "Pattern occurs at indices: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// ============================================================
// Manacher
// ============================================================

void manacher(string &s,
              vector<int> &d1,
              vector<int> &d2) {

    int n = s.size();


    // ========================================================
    // ODD LENGTH PALINDROMES
    //
    // d1[i] = radius of palindrome centered at i
    //
    // Example:
    //
    //       a b a b a
    //           ^
    //         center
    //
    // d1[2] = 3
    //
    // palindrome length = 2*d1[i] - 1
    // ========================================================

    d1.assign(n, 0);

    int l = 0;
    int r = -1;

    for (int i = 0; i < n; i++) {

        int k;

        if (i > r) {

            k = 1;
        }
        else {

            k = min(d1[l + r - i],
                    r - i + 1);
        }

        // Expand palindrome
        while (i - k >= 0 &&
               i + k < n &&
               s[i - k] == s[i + k]) {

            k++;
        }

        d1[i] = k--;

        // Update current palindrome range
        if (i + k > r) {

            l = i - k;
            r = i + k;
        }
    }


    // ========================================================
    // EVEN LENGTH PALINDROMES
    //
    // d2[i] = radius of even palindrome
    //
    // Center is between i-1 and i
    //
    // palindrome length = 2*d2[i]
    // ========================================================

    d2.assign(n, 0);

    l = 0;
    r = -1;

    for (int i = 0; i < n; i++) {

        int k;

        if (i > r) {

            k = 0;
        }
        else {

            k = min(d2[l + r - i + 1],
                    r - i + 1);
        }

        // Expand palindrome
        while (i + k < n &&
               i - k - 1 >= 0 &&
               s[i + k] == s[i - k - 1]) {

            k++;
        }

        d2[i] = k--;

        // Update current palindrome range
        if (i + k > r) {

            l = i - k - 1;
            r = i + k;
        }
    }
}


// ============================================================
// Main
// ============================================================

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    vector<int> d1, d2;

    manacher(s, d1, d2);


    // --------------------------------------------------------
    // Print odd palindrome radii
    // --------------------------------------------------------

    cout << "Odd array (d1): ";

    for (int x : d1) {
        cout << x << " ";
    }

    cout << "\n";


    // --------------------------------------------------------
    // Print even palindrome radii
    // --------------------------------------------------------

    cout << "Even array (d2): ";

    for (int x : d2) {
        cout << x << " ";
    }

    cout << "\n";


    // ========================================================
    // Find longest palindromic substring
    // ========================================================

    int bestLength = 1;
    int bestStart = 0;


    // --------------------------------------------------------
    // Odd palindromes
    // --------------------------------------------------------

    for (int i = 0; i < s.size(); i++) {

        int length = 2 * d1[i] - 1;

        if (length > bestLength) {

            bestLength = length;

            bestStart = i - d1[i] + 1;
        }
    }


    // --------------------------------------------------------
    // Even palindromes
    // --------------------------------------------------------

    for (int i = 0; i < s.size(); i++) {

        int length = 2 * d2[i];

        if (length > bestLength) {

            bestLength = length;

            bestStart = i - d2[i];
        }
    }


    cout << "Longest Palindromic Substring: ";

    cout << s.substr(bestStart, bestLength);

    cout << "\n";

    cout << "Length: "
         << bestLength
         << "\n";


    return 0;
}
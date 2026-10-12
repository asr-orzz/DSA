# Strings

String algorithms as reusable functions + small drivers. Study in any order; KMP and Z are common first picks.

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| KMP | [KMP.cpp](KMP.cpp) | LPS + linear pattern search | Substring search, period structure |
| Z-function | [zAlgo.cpp](zAlgo.cpp) | Longest prefix match at each index | Pattern matching, string hashing prep |
| Rolling hash | [rollingHash.cpp](rollingHash.cpp) | O(1) substring hash with prefix + power table | Compare substrings, duplicate detection |
| Manacher | [manachar's.cpp](manachar's.cpp) | Longest palindromic substring in O(n) | Palindrome centers, odd/even lengths |

## Pick the Right Tool

| Problem hint | Reach for |
|--------------|-----------|
| Find pattern in text | KMP / Z |
| Hash many substrings | Rolling hash |
| Longest palindrome in string | Manacher |

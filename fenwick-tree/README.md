# Fenwick Tree (Binary Indexed Tree)

1-based Fenwick tree templates. Start with [basecode.cpp](basecode.cpp), then apply patterns.

| File | What it does | Typical use |
|------|--------------|-------------|
| [basecode.cpp](basecode.cpp) | Point update + prefix / range sum | Core BIT API |
| [frequencyTable.cpp](frequencyTable.cpp) | Count frequencies with updates | Dynamic frequency, order stats |
| [inversionCount.cpp](inversionCount.cpp) | Inversions via coordinate compression + BIT | Inversion count, merge-style problems |
| [kthSmallest.cpp](kthSmallest.cpp) | k-th smallest with BIT on compressed values | Order statistics on arrays |

## Pick the Right Tool

| Problem hint | Reach for |
|--------------|-----------|
| Point update + range sum on array | basecode |
| Count smaller elements to the right | inversionCount |
| k-th smallest with updates | kthSmallest |

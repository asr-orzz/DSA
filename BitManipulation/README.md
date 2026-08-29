# Bit Manipulation

Reusable bit-level building blocks for CP / interviews. Study top-down (`01` → `07`).

## 01_Basics

| File | What it does |
|------|--------------|
| [bitOps.cpp](01_Basics/bitOps.cpp) | get / set / clear / toggle / update bit, power-of-two check |

## 02_Tricks

| File | What it does |
|------|--------------|
| [tricks.cpp](02_Tricks/tricks.cpp) | popcount (Kernighan + builtin), lowbit `x&-x`, clear-low `x&(x-1)`, `clz`/`ctz`, XOR swap |

## 03_XOR

| File | What it does |
|------|--------------|
| [singleNumber.cpp](03_XOR/singleNumber.cpp) | unique among ×2 / two uniques / unique among ×3 |
| [xorRange.cpp](03_XOR/xorRange.cpp) | XOR of `[L,R]` via period-4 prefix |
| [missingNumber.cpp](03_XOR/missingNumber.cpp) | missing number in `0..n` via XOR |

## 04_Subsets

| File | What it does |
|------|--------------|
| [subsets.cpp](04_Subsets/subsets.cpp) | enumerate all `2^n` subsets by bitmask |
| [submasks.cpp](04_Subsets/submasks.cpp) | iterate submasks of a mask (O(3^n) over all) |

## 05_Contribution

| File | What it does |
|------|--------------|
| [bitContribution.cpp](05_Contribution/bitContribution.cpp) | per-bit contribution: sum of XOR / AND over all pairs |

## 06_BitmaskDP

| File | What it does |
|------|--------------|
| [tsp.cpp](06_BitmaskDP/tsp.cpp) | travelling salesman, `dp[mask][i]` |
| [assignment.cpp](06_BitmaskDP/assignment.cpp) | assign n tasks to n people, min cost |
| [sosDp.cpp](06_BitmaskDP/sosDp.cpp) | sum over subsets |

## 07_XORTrie

| File | What it does |
|------|--------------|
| [maxXorPair.cpp](07_XORTrie/maxXorPair.cpp) | max XOR pair via binary trie (greedy MSB) |

## Pick the Right Tool

| Problem hint | Reach for |
|--------------|-----------|
| Toggle / check individual bits | bitOps |
| Count / isolate set bits | tricks |
| "appears twice/thrice except one" | singleNumber |
| XOR over a range | xorRange |
| Sum of AND/OR/XOR over pairs | bitContribution |
| Enumerate subsets | subsets / submasks |
| n ≤ ~20, visit-all / assignment | Bitmask DP |
| Aggregate over subsets | SOS DP |
| Max XOR of a pair | XOR Trie |

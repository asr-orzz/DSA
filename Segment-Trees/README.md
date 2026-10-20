# Segment Trees

Range-query templates with a binary tree over the array. Start with [basecode.cpp](basecode.cpp). The tree skeleton stays the same; you solve most point-update / range-query problems by changing **node** + **merge** (+ identity).

| File | What it does | Typical use |
|------|--------------|-------------|
| [basecode.cpp](basecode.cpp) | Point update + range sum | Core segment tree API |
| [evenOdd.cpp](evenOdd.cpp) | Custom node: even / odd counts | Same API, richer node; pattern for min+max, gcd+cnt, … |

## Complexity

| Operation | Time | Notes |
|-----------|------|--------|
| Build | O(n) | Recurse to leaves, merge on the way up |
| Point update | O(log n) | One path from root to leaf |
| Range query | O(log n) | O(log n) disjoint node ranges cover `[lq, rq]` |
| Space | O(n) | Tree array sized `4n` |

## Pick the Right Tool

| Problem hint | Reach for |
|--------------|-----------|
| Point update + range sum on array | Segment tree (or Fenwick) |
| Point update + range min / max / XOR / gcd | Same tree; change merge + identity |
| Range update + point query | Fenwick difference, or lazy segment tree |
| Range update + range query | Lazy segment tree |

Fenwick tree is smaller and faster for **sum / XOR / frequency**. Use a segment tree when the merge is not prefix-invertible (min, gcd, …) or you will add lazy later.

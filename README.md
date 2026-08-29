# DSA Revision Templates

Competitive programming / interview revision templates in C++. Each file is a minimal, copy-paste-ready implementation — not a full problem solution.

## Quick Start

- Base boilerplate: [`template.cpp`](template.cpp)
- Graph algos: [`Graphs/README.md`](Graphs/README.md)
- Tree algos (CP, adjacency list): [`Trees/README.md`](Trees/README.md)
- Binary trees (interview, pointer-based): [`BinaryTrees/README.md`](BinaryTrees/README.md)
- Bit manipulation: [`BitManipulation/README.md`](BitManipulation/README.md)

## Structure

```
DSARevision/
├── template.cpp          # base CP template (fast I/O, multi-test)
├── Graphs/               # general graph algorithms
│   ├── 01_Traversal/
│   ├── 02_ShortestPath/
│   ├── 03_TopoAndDAG/
│   ├── 04_MST/
│   ├── 05_Connectivity/
│   └── 06_Advanced/
├── Trees/                # CP rooted trees (adjacency list)
│   ├── 01_Basics/
│   ├── 02_Properties/
│   ├── 03_PathQueries/
│   ├── 04_Flattening/
│   ├── 05_QueriesOnTree/
│   ├── 06_Decomposition/
│   ├── 07_TreeDP/
│   └── 08_Advanced/
├── BinaryTrees/          # pointer-based binary trees (interview / LeetCode)
│   ├── 01_Basics/
│   ├── 02_Traversals/
│   ├── 03_BasicProblems/
│   ├── 04_PathProblems/
│   ├── 05_Construction/
│   ├── 06_Views/
│   ├── 07_BST/
│   └── 08_Advanced/
└── BitManipulation/      # bit tricks, XOR, bitmask DP
    ├── 01_Basics/
    ├── 02_Tricks/
    ├── 03_XOR/
    ├── 04_Subsets/
    ├── 05_Contribution/
    ├── 06_BitmaskDP/
    └── 07_XORTrie/
```

## How to Study

1. Pick a topic folder and go top-down (numbered folders = suggested order).
2. Open the `.cpp` file — read the top comment for **time complexity** and **when to use**.
3. Skim the flow: input → build graph → run algo → use result.
4. Cross-check with the topic README for a one-line **application** per algo.

## Conventions

| Item | Choice |
|------|--------|
| Language | C++17 (`bits/stdc++.h`) |
| Indexing | 1-based nodes (`n+1` size) |
| Weights / INF | `ll` + `1e18` for weighted; `1e9` for unweighted |
| Graph storage | Adjacency list; matrix only for Floyd-Warshall |
| I/O | Fast I/O in every file |

## Topics

### [Graphs](Graphs/README.md) — 21 templates

| Section | Count | Covers |
|---------|-------|--------|
| [01_Traversal](Graphs/README.md#01_traversal) | 5 | BFS, DFS, multisource BFS, bipartite, cycle |
| [02_ShortestPath](Graphs/README.md#02_shortestpath) | 5 | Dijkstra, 0-1 BFS, Bellman-Ford, Floyd-Warshall |
| [03_TopoAndDAG](Graphs/README.md#03_topoanddag) | 2 | Kahn, DAG shortest path |
| [04_MST](Graphs/README.md#04_mst) | 3 | DSU, Kruskal, Prim |
| [05_Connectivity](Graphs/README.md#05_connectivity) | 3 | Kosaraju, bridges, articulation points |
| [06_Advanced](Graphs/README.md#06_advanced) | 3 | Euler path, Dinic, 2-SAT |

### [Trees](Trees/README.md) — 13 templates

| Section | Count | Covers |
|---------|-------|--------|
| [01_Basics](Trees/README.md#01_basics) | 1 | Tree DFS (par, depth, height, subtree) |
| [02_Properties](Trees/README.md#02_properties) | 3 | Diameter, center, centroid |
| [03_PathQueries](Trees/README.md#03_pathqueries) | 1 | LCA, k-ancestor, distance, k-th on path |
| [04_Flattening](Trees/README.md#04_flattening) | 1 | Euler tour (tin/tout) |
| [05_QueriesOnTree](Trees/README.md#05_queriesontree) | 2 | HLD, virtual tree |
| [06_Decomposition](Trees/README.md#06_decomposition) | 1 | Centroid decomposition |
| [07_TreeDP](Trees/README.md#07_treedp) | 2 | Basic tree DP, rerooting DP |
| [08_Advanced](Trees/README.md#08_advanced) | 2 | DSU on tree, tree hashing |

### [BinaryTrees](BinaryTrees/README.md) — 26 templates

| Section | Count | Covers |
|---------|-------|--------|
| [01_Basics](BinaryTrees/README.md#01_basics) | 1 | Node struct + build |
| [02_Traversals](BinaryTrees/README.md#02_traversals) | 6 | pre/in/post (rec+iter), level, zigzag, Morris |
| [03_BasicProblems](BinaryTrees/README.md#03_basicproblems) | 6 | height, count, diameter, same, balanced, symmetric |
| [04_PathProblems](BinaryTrees/README.md#04_pathproblems) | 4 | root-to-leaf, max path sum, LCA, distance |
| [05_Construction](BinaryTrees/README.md#05_construction) | 3 | build from in+pre / in+post, serialize |
| [06_Views](BinaryTrees/README.md#06_views) | 4 | left/right, top/bottom, vertical, boundary |
| [07_BST](BinaryTrees/README.md#07_bst) | 6 | search, insert, delete, validate, kth, LCA |
| [08_Advanced](BinaryTrees/README.md#08_advanced) | 1 | flatten |

### [BitManipulation](BitManipulation/README.md) — 13 templates

| Section | Count | Covers |
|---------|-------|--------|
| [01_Basics](BitManipulation/README.md#01_basics) | 1 | get/set/clear/toggle bit, power-of-two |
| [02_Tricks](BitManipulation/README.md#02_tricks) | 1 | popcount, lowbit, clz/ctz, XOR swap |
| [03_XOR](BitManipulation/README.md#03_xor) | 3 | single number, XOR range, missing number |
| [04_Subsets](BitManipulation/README.md#04_subsets) | 2 | subset + submask enumeration |
| [05_Contribution](BitManipulation/README.md#05_contribution) | 1 | per-bit contribution technique |
| [06_BitmaskDP](BitManipulation/README.md#06_bitmaskdp) | 3 | TSP, assignment, SOS DP |
| [07_XORTrie](BitManipulation/README.md#07_xortrie) | 1 | max XOR pair |

## Pick the Right Algo (Graphs)

| Problem hint | Reach for |
|--------------|-----------|
| Unweighted shortest path | BFS |
| Weights ≥ 0 | Dijkstra |
| Weights 0 or 1 only | 0-1 BFS |
| Negative edges | Bellman-Ford |
| All-pairs / dense graph | Floyd-Warshall |
| Dependency order | Kahn or DFS topo |
| Min cost connect all | Kruskal / Prim |
| Strongly connected pieces | Kosaraju |
| Critical edge / cut vertex | Bridges / articulation points |
| Max flow / matching | Dinic |
| Boolean constraints (A ∨ B) | 2-SAT |

## Pick the Right Algo (Trees)

| Problem hint | Reach for |
|--------------|-----------|
| Parent / depth / subtree | [Tree DFS](Trees/01_Basics/treeDfs.cpp) |
| Longest path | [Diameter](Trees/02_Properties/diameter.cpp) |
| LCA / distance | [Binary Lifting](Trees/03_PathQueries/lca.cpp) |
| Subtree as range | [Euler Tour](Trees/04_Flattening/eulerTour.cpp) |
| Path as O(log N) chains | [HLD](Trees/05_QueriesOnTree/hld.cpp) |
| k special nodes | [Virtual Tree](Trees/05_QueriesOnTree/virtualTree.cpp) |
| Take/skip on tree | [Tree DP](Trees/07_TreeDP/basicTreeDp.cpp) |

## Adding New Templates

1. Create or use a topic folder (e.g. `Graphs/`, `Trees/`, or a new top-level folder).
2. Match existing style: global `n, m`, adjacency list, fast I/O, complexity comment at top.
3. Update that topic's `README.md` with algo name, link, and one-line application.

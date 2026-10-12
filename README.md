# DSA Revision Templates

Competitive programming / interview revision templates in C++. Each file is a minimal, copy-paste-ready implementation — not a full problem solution.

## Quick Start

- Base boilerplate: [`template.cpp`](template.cpp)
- Graph algos: [`Graphs/README.md`](Graphs/README.md)
- Tree algos (CP, adjacency list): [`Trees/README.md`](Trees/README.md)
- Binary trees (interview, pointer-based): [`BinaryTrees/README.md`](BinaryTrees/README.md)
- Bit manipulation: [`BitManipulation/README.md`](BitManipulation/README.md)
- Maths / number theory: [`Maths/README.md`](Maths/README.md)
- Greedy: [`Greedy/README.md`](Greedy/README.md)
- Strings: [`strings/README.md`](strings/README.md)
- Fenwick tree: [`fenwick-tree/README.md`](fenwick-tree/README.md)
- Design problems: [`Algorithmic-Designs/README.md`](Algorithmic-Designs/README.md)

## Structure

```
DSARevision/
├── template.cpp              # base CP template (fast I/O, multi-test)
├── Graphs/                     # general graph algorithms (01_ … 06_)
├── Trees/                      # CP rooted trees (adjacency list)
├── BinaryTrees/                # pointer-based binary trees (interview)
├── BitManipulation/            # bit tricks, XOR, bitmask DP
├── Maths/                      # number theory, primes, …
├── Greedy/                     # greedy templates with problem write-ups
├── strings/                    # KMP, Z, hashing, Manacher
├── fenwick-tree/               # BIT templates
└── Algorithmic-Designs/        # LRU, LFU, min stack, snapshot array
```

Numbered subfolders (`01_Basics`, `02_…`) suggest study order within a topic. Each topic has its own `README.md` with a file index and “when to use” hints.

## How to Write Code Here

Two header styles appear in the repo — pick one that fits the file:

| Style | Where | What to include |
|-------|--------|-----------------|
| **Short algo note** | Graphs, Trees, BitManipulation, Maths, strings | `// Time: …` (and space if useful), then reusable functions or a small class |
| **Full problem brief** | Greedy (e.g. activity selection) | Block comment: problem, example, greedy idea, time/space, then stepped `main` |

**Shared body conventions**

1. `#include <bits/stdc++.h>` and `using namespace std;`
2. `typedef long long ll` when weights or large sums matter
3. **Reusable core** — named functions (`vector<int> sieve(int n)`, `computeLPS`, …) or a class (`FenwickTree`, `LRUCache`) that you can lift into contests
4. **`main`** — fast I/O (`ios_base::sync_with_stdio(0); cin.tie(0);`) and a tiny driver (read input, call the algo, print)
5. **CP graphs/trees** — 1-based indexing where noted (`n+1` arrays, adjacency size `n+1`)
6. **Binary trees** — level-order build with `-1` as null; see [BinaryTrees/01_Basics/node.cpp](BinaryTrees/01_Basics/node.cpp)

When you add a file: match the folder’s style, keep the implementation minimal, and add a row to that topic’s `README.md`.

## How to Study

1. Pick a topic folder and go top-down (numbered folders = suggested order).
2. Open the `.cpp` file — read the top comment for **time complexity** and **when to use**.
3. Skim the flow: input → build structure → run algo → use result.
4. Cross-check with the topic README for a one-line **application** per algo.

## Conventions

| Item | Choice |
|------|--------|
| Language | C++17 (`bits/stdc++.h`) |
| Indexing | 1-based nodes (`n+1` size) for graphs/trees/BIT |
| Weights / INF | `ll` + `1e18` for weighted; `1e9` for unweighted |
| Graph storage | Adjacency list; matrix only for Floyd-Warshall |
| I/O | Fast I/O in contest-style files |

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

### [Maths](Maths/README.md) — 1 template

| Section | Count | Covers |
|---------|-------|--------|
| [01_Primes](Maths/README.md#01_primes) | 1 | Sieve of Eratosthenes |

### [Greedy](Greedy/README.md) — 1 template

| File | Covers |
|------|--------|
| [Scheduling.cpp](Greedy/Scheduling.cpp) | Activity selection (sort by end time) |

### [strings](strings/README.md) — 4 templates

KMP, Z-algorithm, rolling hash, Manacher.

### [fenwick-tree](fenwick-tree/README.md) — 4 templates

Base BIT, frequency table, inversion count, k-th smallest.

### [Algorithmic-Designs](Algorithmic-Designs/README.md) — 5 templates

LRU, LFU, min stack, stack increment, snapshot array.

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

1. Create or use a topic folder (e.g. `Maths/01_Primes/`).
2. Match existing style: reusable function or class, fast I/O, complexity at top.
3. Update that topic's `README.md` and, if new top-level topic, this file's **Quick Start** and **Topics** tables.

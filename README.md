# DSA Revision Templates

Competitive programming / interview revision templates in C++. Each file is a minimal, copy-paste-ready implementation — not a full problem solution.

## Quick Start

- Base boilerplate: [`template.cpp`](template.cpp)
- Graph algos: [`Graphs/README.md`](Graphs/README.md)
- Tree algos: [`Trees/README.md`](Trees/README.md)

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
└── Trees/                # tree-specific algorithms (separate from Graphs)
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

### [Trees](Trees/README.md) — 1 template

| Algo | File | Use |
|------|------|-----|
| LCA (Binary Lifting) | [`Trees/lca.cpp`](Trees/lca.cpp) | Ancestor queries, tree distances |

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

## Adding New Templates

1. Create or use a topic folder (e.g. `Graphs/`, `Trees/`, or a new top-level folder).
2. Match existing style: global `n, m`, adjacency list, fast I/O, complexity comment at top.
3. Update that topic's `README.md` with algo name, link, and one-line application.

# Graphs

Study top-down (`01` → `06`). Each file is a revision template.

## 01_Traversal

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| BFS | [bfs.cpp](01_Traversal/bfs.cpp) | Level-order traversal; unweighted shortest path | Distances, nearest node, grid flood |
| DFS | [dfs.cpp](01_Traversal/dfs.cpp) | Depth-first search; topo order + directed cycle | Reachability, DAG check, path existence |
| Multisource BFS | [multisourceBfs.cpp](01_Traversal/multisourceBfs.cpp) | BFS from many sources at once | Closest wall/gate, multi-fire spread |
| Bipartite | [bipartite.cpp](01_Traversal/bipartite.cpp) | 2-coloring; detects odd cycles | Matching setup, conflict graphs |
| Undirected Cycle | [cycleUndirected.cpp](01_Traversal/cycleUndirected.cpp) | Cycle check in undirected graph | Redundant edge, tree validation |

## 02_ShortestPath

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Dijkstra | [djk.cpp](02_ShortestPath/djk.cpp) | Non-negative weighted SSSP | Road networks, weighted grids |
| Dijkstra + Path | [djkPath.cpp](02_ShortestPath/djkPath.cpp) | Dijkstra with parent reconstruction | Print actual route |
| 0-1 BFS | [01bfs.cpp](02_ShortestPath/01bfs.cpp) | Deque BFS when edge weights are 0/1 | Grid cost flips, free vs paid moves |
| Bellman-Ford | [bellmanFord.cpp](02_ShortestPath/bellmanFord.cpp) | SSSP with negatives; detects neg cycles | Arbitrage, constraint diffs |
| Floyd-Warshall | [floydWarshall.cpp](02_ShortestPath/floydWarshall.cpp) | All-pairs shortest paths (O(V³)) | Dense graphs, APSP, reachability matrix |

## 03_TopoAndDAG

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Kahn | [kahnsAlgo.cpp](03_TopoAndDAG/kahnsAlgo.cpp) | BFS topo sort via indegrees | Course order, build dependencies |
| DAG Shortest Path | [dagShortestPath.cpp](03_TopoAndDAG/dagShortestPath.cpp) | Topo + relax; linear SP on DAGs | Critical path, task scheduling |

## 04_MST

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| DSU | [dsu.cpp](04_MST/dsu.cpp) | Union-Find / components | Connectivity queries, Kruskal base |
| Kruskal | [kruskal.cpp](04_MST/kruskal.cpp) | MST by sorting edges + DSU | Min wiring, cluster merge |
| Prim | [prim.cpp](04_MST/prim.cpp) | MST by growing a tree (PQ) | Dense MST, prim-style growth |

## 05_Connectivity

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Kosaraju | [kosaraju.cpp](05_Connectivity/kosaraju.cpp) | SCCs + condensation DAG | Condensation, 2-SAT base |
| Bridges | [bridges.cpp](05_Connectivity/bridges.cpp) | Critical edges (Tarjan) | Network weak links |
| Articulation Points | [articulationPoints.cpp](05_Connectivity/articulationPoints.cpp) | Cut vertices | Single-point failures |

## 06_Advanced

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Euler Path | [eulerPath.cpp](06_Advanced/eulerPath.cpp) | Traverse every edge once (Hierholzer) | Chinese Postman, circuit tours |
| Dinic | [dinic.cpp](06_Advanced/dinic.cpp) | Max flow | Bipartite matching, cuts, routing |
| 2-SAT | [twoSat.cpp](06_Advanced/twoSat.cpp) | Satisfiability of 2-CNF via SCC | Implication constraints, pairing choices |

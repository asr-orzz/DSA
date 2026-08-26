# Trees

Tree-specific algorithms. Study top-down (`01` → `08`).

For **BFS/DFS on graphs** see [Graphs/01_Traversal](../Graphs/README.md#01_traversal).  
For **range queries on flattened trees** use Euler tour / HLD here, then plug in **SegmentTree** (separate folder, coming soon).

## 01_Basics

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Tree DFS | [treeDfs.cpp](01_Basics/treeDfs.cpp) | Root tree; parent, depth, height, subtree size | Foundation for all tree algos |

## 02_Properties

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Diameter | [diameter.cpp](02_Properties/diameter.cpp) | Longest path via 2× BFS/DFS | Tree width, farthest pair |
| Center | [center.cpp](02_Properties/center.cpp) | Node(s) with min eccentricity | Optimal meeting point |
| Centroid | [centroid.cpp](02_Properties/centroid.cpp) | Node where no subtree > n/2 | Balance split, centroid decomp base |

## 03_PathQueries

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| LCA + Binary Lifting | [lca.cpp](03_PathQueries/lca.cpp) | LCA, k-th ancestor, distance, k-th on path | Path queries, ancestry checks |

## 04_Flattening

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Euler Tour | [eulerTour.cpp](04_Flattening/eulerTour.cpp) | tin/tout; subtree → range | Subtree queries via SegmentTree |

## 05_QueriesOnTree

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| HLD | [hld.cpp](05_QueriesOnTree/hld.cpp) | Heavy-light chains + pos[] array | Path queries (needs SegmentTree) |
| Virtual Tree | [virtualTree.cpp](05_QueriesOnTree/virtualTree.cpp) | Compress k special nodes + LCAs | DP on few nodes only |

## 06_Decomposition

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Centroid Decomposition | [centroidDecomposition.cpp](06_Decomposition/centroidDecomposition.cpp) | Divide at centroids recursively | Count paths through centroid |

## 07_TreeDP

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Basic Tree DP | [basicTreeDp.cpp](07_TreeDP/basicTreeDp.cpp) | Take/skip states on tree | Independent set, vertex cover pattern |
| Rerooting DP | [rerootingDp.cpp](07_TreeDP/rerootingDp.cpp) | Answer for every root in O(n) | Sum of distances, tree DP reroot |

## 08_Advanced

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| DSU on Tree | [dsuOnTree.cpp](08_Advanced/dsuOnTree.cpp) | Small-to-large subtree merging | Subtree distinct count / frequency |
| Tree Hash | [treeHash.cpp](08_Advanced/treeHash.cpp) | Hash rooted subtrees | Subtree equality, isomorphism |

## Pick the Right Algo

| Problem hint | Reach for |
|--------------|-----------|
| Parent / depth / subtree size | Tree DFS |
| Longest path in tree | Diameter |
| Best meeting point | Center |
| Balance / divide tree | Centroid |
| LCA / distance / k-th ancestor | Binary Lifting |
| Subtree = contiguous range | Euler Tour |
| Path sum/min with updates | HLD + SegmentTree |
| k special nodes only | Virtual Tree |
| Paths through a node | Centroid Decomposition |
| Take or skip nodes | Tree DP |
| Answer for every root | Rerooting DP |
| Subtree frequency queries | DSU on Tree |

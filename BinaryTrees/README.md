# Binary Trees

Pointer-based binary trees (`struct Node{ int val; Node *left,*right; }`) — interview / LeetCode flavored. Study top-down (`01` → `08`).

Different from [Trees/](../Trees/README.md), which is CP-style rooted trees on adjacency lists.

**Input convention** (see [node.cpp](01_Basics/node.cpp)): `m`, then `m` tokens in level order, `-1` = null child.

## 01_Basics

| File | What it does |
|------|--------------|
| [node.cpp](01_Basics/node.cpp) | Node struct + build tree from level-order input |

## 02_Traversals

| File | What it does |
|------|--------------|
| [preorder.cpp](02_Traversals/preorder.cpp) | Root-Left-Right (recursive + iterative) |
| [inorder.cpp](02_Traversals/inorder.cpp) | Left-Root-Right (recursive + iterative) |
| [postorder.cpp](02_Traversals/postorder.cpp) | Left-Right-Root (recursive + 1-stack + 2-stack) |
| [levelOrder.cpp](02_Traversals/levelOrder.cpp) | BFS grouped level by level |
| [zigzag.cpp](02_Traversals/zigzag.cpp) | Spiral level order |
| [morris.cpp](02_Traversals/morris.cpp) | O(1) space inorder + preorder (threading) |

## 03_BasicProblems

| File | What it does |
|------|--------------|
| [height.cpp](03_BasicProblems/height.cpp) | Height / max depth |
| [countNodes.cpp](03_BasicProblems/countNodes.cpp) | Count all, leaves, sum of values |
| [diameter.cpp](03_BasicProblems/diameter.cpp) | Longest path between any two nodes |
| [sameTree.cpp](03_BasicProblems/sameTree.cpp) | Two trees identical |
| [balanced.cpp](03_BasicProblems/balanced.cpp) | Height-balanced check |
| [symmetric.cpp](03_BasicProblems/symmetric.cpp) | Mirror of itself |

## 04_PathProblems

| File | What it does |
|------|--------------|
| [rootToLeaf.cpp](04_PathProblems/rootToLeaf.cpp) | All root-to-leaf paths + path-number sum |
| [maxPathSum.cpp](04_PathProblems/maxPathSum.cpp) | Max path sum (bends at a node) |
| [lca.cpp](04_PathProblems/lca.cpp) | LCA in a general binary tree |
| [distance.cpp](04_PathProblems/distance.cpp) | Distance between two nodes via LCA |

## 05_Construction

| File | What it does |
|------|--------------|
| [buildFromInPre.cpp](05_Construction/buildFromInPre.cpp) | Build from Inorder + Preorder |
| [buildFromInPost.cpp](05_Construction/buildFromInPost.cpp) | Build from Inorder + Postorder |
| [serialize.cpp](05_Construction/serialize.cpp) | Serialize / deserialize (preorder + `#`) |

## 06_Views

| File | What it does |
|------|--------------|
| [leftRightView.cpp](06_Views/leftRightView.cpp) | Left view + right view |
| [topBottomView.cpp](06_Views/topBottomView.cpp) | Top view + bottom view (by hd) |
| [verticalOrder.cpp](06_Views/verticalOrder.cpp) | Vertical order traversal |
| [boundary.cpp](06_Views/boundary.cpp) | Boundary (anti-clockwise) traversal |

## 07_BST

| File | What it does |
|------|--------------|
| [search.cpp](07_BST/search.cpp) | Search + min/max |
| [insert.cpp](07_BST/insert.cpp) | Insert |
| [deleteNode.cpp](07_BST/deleteNode.cpp) | Delete (0/1/2 children) |
| [validate.cpp](07_BST/validate.cpp) | Validate BST via (low, high) |
| [kthSmallest.cpp](07_BST/kthSmallest.cpp) | Kth smallest (inorder) |
| [lcaBST.cpp](07_BST/lcaBST.cpp) | LCA using BST ordering |

## 08_Advanced

| File | What it does |
|------|--------------|
| [flatten.cpp](08_Advanced/flatten.cpp) | Flatten to right-skewed list (preorder) |

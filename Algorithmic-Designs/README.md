# Algorithmic Designs

Classic data-structure design problems (often LeetCode-style). Each file is a self-contained class + usage.

| Design | File | What it does |
|--------|------|--------------|
| LRU cache | [LRU.cpp](LRU.cpp) | O(1) get/put with capacity; list + hash map |
| LFU cache | [LFU.cpp](LFU.cpp) | Least frequently used eviction |
| Min stack | [minStack.cpp](minStack.cpp) | Stack with O(1) minimum |
| Stack with increment | [stackIncrement.cpp](stackIncrement.cpp) | Increment bottom k elements |
| Snapshot array | [snapshotArray.cpp](snapshotArray.cpp) | Versioned array reads |

## Pick the Right Tool

| Problem hint | Reach for |
|--------------|-----------|
| Cache with recency | LRU |
| Cache with frequency | LFU |
| Min on stack operations | minStack |
| Historical array state | snapshotArray |

# Greedy

Greedy choice templates with full problem context in file headers. Study in folder order.

## Templates

| Problem | File | Greedy rule | Complexity |
|---------|------|-------------|------------|
| Activity selection (max non-overlapping intervals) | [Scheduling.cpp](Scheduling.cpp) | Sort by end time; take if start ≥ last end | O(n log n) |

## When greedy is enough vs not

| Goal | Approach |
|------|----------|
| Max **count** of compatible intervals (unit profit) | Sort by end → activity selection |
| Max **total profit** with weights | DP + binary search (weighted interval scheduling) |

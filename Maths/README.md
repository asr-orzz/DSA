# Maths

Number theory and math building blocks for CP / interviews. Study top-down (`01` → …).

## 01_Primes

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Sieve of Eratosthenes | [sieve.cpp](01_Primes/sieve.cpp) | Mark composites; list all primes ≤ n | Prime table, factorization prep, counting primes |

## 02_Combinatorics

| Algo | File | What it does | Typical use |
|------|------|--------------|-------------|
| Derangements | [derangement.cpp](02_Combinatorics/derangement.cpp) | D_n via (n−1)(D_{n−1}+D_{n−2}) mod M | Permutations with no fixed point, counting problems |

## Pick the Right Tool

| Problem hint | Reach for |
|--------------|-----------|
| All primes up to n / many prime checks | Sieve |
| No element in its original position | Derangement recurrence |

# Knapsack Problem — Approaches used in the code

This folder contains implementations and notes for the common variants of the knapsack problem. The source file is `01Knapsack.cpp` (0/1 knapsack). Below are the approaches demonstrated and tips for each variant.

Knapsack variants covered

- 0/1 Knapsack
- Fractional Knapsack
- Unbounded (unbound) Knapsack

## 0/1 Knapsack

Description

In the 0/1 knapsack each item may be taken at most once. The implementations provided demonstrate two standard approaches:

1) Recursive (brute-force) + Memoization (top-down DP)
	- Idea: For each item index i and remaining capacity W, choose between taking the item (if it fits) or skipping it. This yields a recursion with overlapping subproblems.
	- Memoization: store results in a table keyed by (i, W) to avoid exponential recomputation.
	- When to use: good to prototype and to understand the state transitions.

2) Iterative DP (bottom-up / tabulation)
	- Idea: Build a DP table dp[i][w] that stores the maximum value using items up to i with capacity w. Typical transitions iterate items and capacities.
	- Space-optimized version: use a 1D dp[w] array and iterate items in reverse (for 0/1 constraint) to reuse space.
	- When to use: preferred for performance and clarity in production/contests.

Complexity (typical)
 - Recursive (without memo): O(2^n) time, O(n) recursion depth.
 - Recursive + memo or iterative DP: O(n * W) time and O(n * W) space.
 - Space-optimized iterative DP: O(n * W) time and O(W) space.

Edge cases and notes
 - Capacity W = 0 or no items => result 0.
 - Large W (or large weights) may make O(n*W) impractical — consider alternate approximations or meet-in-the-middle if constraints allow.

## Fractional Knapsack

Description

In the Fractional Knapsack you can take fractions of items. The greedy strategy is optimal:

- Sort items by value/weight ratio (descending).
- Take as much as possible of the highest-ratio item, then continue until the capacity is exhausted.

Complexity
 - Sorting dominates: O(n log n) time, O(1) or O(n) extra space depending on sort.

When to use
 - When fractional items are allowed (continuous knapsack). Not applicable to 0/1 variants.

## Unbounded Knapsack

Description

In the unbounded knapsack each item may be taken unlimited times. Approaches include:

- Iterative DP (similar to 0/1 but inner loops differ): dp[w] = max(dp[w], dp[w - wt[i]] + val[i]) iterating capacities from wt[i] to W.
- The order of loops matters depending on whether you want combinations or permutations; for standard max-value, iterate items outer and capacities inner (ascending) to allow reuse.

Complexity
 - O(n * W) time, O(W) space (or O(n * W) space for full table).

## Example mapping to files

- `01Knapsack.cpp` — contains implementations for 0/1 knapsack (recursive + memo and iterative DP). See comments in the file for usage and small test harness.

## Quick implementation tips

- Prefer memoization when writing a correct, easy-to-debug solution quickly.
- Switch to iterative DP and space optimization for speed and lower memory in contest settings.
- Always check for integer overflow when values are large — use 64-bit integers where necessary.
- Add small test cases: empty items, capacity 0, single item bigger than capacity, many small items.

## References

- Standard algorithm textbooks and competitive programming notes on knapsack (0/1, fractional, unbounded).

---
If you want, I can add a short example input/output section and a small runner script demonstrating `01Knapsack.cpp` usage.


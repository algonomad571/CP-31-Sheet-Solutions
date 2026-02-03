# 🟦 Count Subrectangles — Product Matrix Insight

## 🧠 Problem Overview

You are given two binary arrays:
- `a` of length `n`
- `b` of length `m`

A matrix `c` of size `n × m` is defined as:
\[
c_{i,j} = a_i \times b_j
\]

So every cell in `c` is either `0` or `1`.

Your task is to count how many **subrectangles of area exactly `k`** consist **only of `1`s**.

---

## 🎯 Objective

Count the number of subrectangles in matrix `c`:
- Made entirely of `1`s
- Having **area = k**

---

## 🔑 Key Insight

A cell `c[i][j]` is `1` **if and only if**:
- `a[i] = 1`
- `b[j] = 1`

This means:
- Rows and columns are **independent**
- A valid subrectangle corresponds to:
  - A consecutive segment of `1`s in `a` (height)
  - A consecutive segment of `1`s in `b` (width)

---

## 🧩 Reformulation

Let:
- `h` = height of subrectangle (rows)
- `w` = width of subrectangle (columns)

Then:
\[
h \times w = k
\]

So we need to count:
- Number of ways to choose a height `h` from array `a`
- Number of ways to choose a width `w` from array `b`
- Such that `h × w = k`

---

## 📐 Counting Consecutive Ones

For a consecutive block of `1`s of length `L`:
- Number of subsegments of length `x` is:
\[
\max(0, L - x + 1)
\]

We compute:
- `cntA[x]` → number of subsegments of length `x` in `a`
- `cntB[x]` → number of subsegments of length `x` in `b`

---

## 🧮 Final Counting Strategy

For each divisor `h` of `k`:
- Let `w = k / h`
- Add:
\[
cntA[h] \times cntB[w]
\]

Also consider `(w, h)` if `h ≠ w`.

---

## ⚙️ Algorithm Summary

1. Scan array `a` and count consecutive `1` segments
2. For each segment, update counts of all possible subsegment lengths
3. Repeat the same for array `b`
4. Iterate over all divisors of `k`
5. Sum valid combinations

---

## ⏱️ Complexity Analysis

- **Time Complexity:**  
  `O(n + m + √k)`

- **Space Complexity:**  
  `O(n + m)`

Efficient for constraints up to `40,000`.

---

## 🧠 Key Takeaways

- Avoid constructing the full matrix
- Use mathematical structure of the problem
- Reduce 2D counting to 1D segment combinations

---

## 🏷️ Tags

`Arrays` · `Math` · `Combinatorics` · `Two Pointers` · `Implementation`

---

## ⭐ Final Note

This problem is a great example of how recognizing **independence between dimensions** can drastically simplify an apparently complex 2D problem.
